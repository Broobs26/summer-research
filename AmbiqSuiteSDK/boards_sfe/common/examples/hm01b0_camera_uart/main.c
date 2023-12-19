// based on demo from Himax

// This is the file that I will be using to implement the I2C Protocol between 
// TODO: Continue porting ios_lram.c over to the while(1) part of main
// TODO: Edit to deal with data from NUCLEO-64

/*
Copyright (c) 2019 SparkFun Electronics

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <string.h>
#include "am_mcu_apollo.h"
#include "am_bsp.h"
#include "am_util.h"
#include "HM01B0.h"
#include "HM01B0_RAW8_QVGA_8bits_lsb_5fps.h"
#include "platform.h"

//*****************************************************************************
//
// I2C Setup
//
//*****************************************************************************
#define I2C_SLAVE_ADDR  0x10

#define report(s) am_util_stdio_printf("status: 0x%08X (function: %s, file: %s, line: %d)\r\n", s, __PRETTY_FUNCTION__, __FILE__, __LINE__)

#define TEST_IOS_XCMP_INT   1

#define AM_HAL_IOS_INT_ERR  (AM_HAL_IOS_INT_FOVFL | AM_HAL_IOS_INT_FUNDFL | AM_HAL_IOS_INT_FRDERR)

#define AM_HAL_IOS_XCMP_INT (AM_HAL_IOS_INT_XCMPWR | AM_HAL_IOS_INT_XCMPWF | AM_HAL_IOS_INT_XCMPRR | AM_HAL_IOS_INT_XCMPRF)

#define AM_IOSTEST_CMD_SEND_DATA    0xFC
#define AM_IOSTEST_CMD_START_DATA   0xFD
#define AM_IOSTEST_CMD_ACK_DATA     0xFE
#define AM_IOSTEST_CMD_STOP_DATA    0xFF

#define HANDSHAKE_IOS_TO_IOM        2

#define INBUFFER_EMPTY              (0xEE)
#define TEST_XOR_BYTE               0xFF
#define ROBUFFER_INIT               (0x55)

typedef struct 
{
    uint8_t ui8Tag;
    uint8_t ui8Length;
}sHeader;

typedef enum
{
    IOM_DATA_TAG,
    IOM_DATA_LENGTH,
    IOM_DATA_VALUE
}eIOM_Data;

static void *g_pIOSHandle;
volatile bool bIomSendComplete = true;

//*****************************************************************************
//
// Message buffers.
//
// data from the IOS interface, which is only 8 bits wide.
//
//*****************************************************************************
#define AM_IOS_LRAM_SIZE_MAX    0x78
uint8_t g_pIosSendBuf[AM_IOS_LRAM_SIZE_MAX];
#define AM_IOS_HEADER_SIZE      sizeof(sHeader)
#define AM_IOS_MAX_DATA_SIZE    (AM_IOS_LRAM_SIZE_MAX - AM_IOS_HEADER_SIZE)

//*****************************************************************************
//
// I2C Slave Configuration
//
//*****************************************************************************
am_hal_ios_config_t g_sIOSI2cConfig =
{
    .ui32InterfaceSelect = AM_HAL_IOS_USE_I2C | AM_HAL_IOS_I2C_ADDRESS(I2C_SLAVE_ADDR << 1),
    .ui32ROBase = 0x78,
    .ui32FIFOBase = 0x80,
    .ui32RAMBase = 0x100,
    .ui32FIFOThreshold = 0x40,
};

// #define DEMO_HM01B0_TEST_MODE_ENABLE
#define DEMO_HM01B0_FRAMEBUFFER_DUMP_ENABLE

//*****************************************************************************
//
// HM01B0 Configuration
//
//*****************************************************************************
static hm01b0_cfg_t         s_HM01B0Cfg =
{
    // i2c settings
    .ui16SlvAddr                = HM01B0_DEFAULT_ADDRESS,
    .eIOMMode                   = HM01B0_IOM_MODE,
    .ui32IOMModule              = HM01B0_IOM_MODULE,
    .sIOMCfg                    =
        {
            .eInterfaceMode     = HM01B0_IOM_MODE,
            .ui32ClockFreq      = HM01B0_I2C_CLOCK_FREQ,
        },
    .pIOMHandle                 = NULL,
    .ui8PinSCL                  = HM01B0_PIN_SCL,
    .ui8PinSDA                  = HM01B0_PIN_SDA,

    // MCLK settings
    .ui32CTimerModule           = HM01B0_MCLK_GENERATOR_MOD,
    .ui32CTimerSegment          = HM01B0_MCLK_GENERATOR_SEG,
    .ui32CTimerOutputPin        = HM01B0_PIN_MCLK,

    // data interface
    .ui8PinD0                   = HM01B0_PIN_D0,
    .ui8PinD1                   = HM01B0_PIN_D1,
    .ui8PinD2                   = HM01B0_PIN_D2,
    .ui8PinD3                   = HM01B0_PIN_D3,
    .ui8PinD4                   = HM01B0_PIN_D4,
    .ui8PinD5                   = HM01B0_PIN_D5,
    .ui8PinD6                   = HM01B0_PIN_D6,
    .ui8PinD7                   = HM01B0_PIN_D7,
    .ui8PinVSYNC                = HM01B0_PIN_VSYNC,
    .ui8PinHSYNC                = HM01B0_PIN_HSYNC,
    .ui8PinPCLK                 = HM01B0_PIN_PCLK,

#ifdef HM01B0_PIN_TRIG
    .ui8PinTrig                 = HM01B0_PIN_TRIG,
#endif // HM01B0_PIN_TRIG

#ifdef HM01B0_PIN_INT
    .ui8PinInt                  = HM01B0_PIN_INT,
#endif // HM01B0_PIN_INT

    .pfnGpioIsr                 = NULL,
};

static uint8_t s_ui8FrameBuffer[HM01B0_PIXEL_X_NUM * HM01B0_PIXEL_Y_NUM];

//*****************************************************************************
//
// High Speed UART Configuration
//
//*****************************************************************************
static const am_hal_uart_config_t g_sBspUartConfigHS =
{
    //
    // Standard UART settings: 115200-8-N-1
    //
    .ui32BaudRate = 115200,
    .ui32DataBits = AM_HAL_UART_DATA_BITS_8,
    .ui32Parity = AM_HAL_UART_PARITY_NONE,
    .ui32StopBits = AM_HAL_UART_ONE_STOP_BIT,
    .ui32FlowControl = AM_HAL_UART_FLOW_CTRL_NONE,

    //
    // Set TX and RX FIFOs to interrupt at half-full.
    //
    .ui32FifoLevels = (AM_HAL_UART_TX_FIFO_1_2 |
                    AM_HAL_UART_RX_FIFO_1_2),

    //
    // The default interface will just use polling instead of buffers.
    //
    .pui8TxBuffer = 0,
    .ui32TxBufferSize = 0,
    .pui8RxBuffer = 0,
    .ui32RxBufferSize = 0,
};

//*****************************************************************************
//
// Forward declarations
//
//*****************************************************************************
void boost_mode_enable(bool bEnable);
void am_gpio_isr(void);
void framebuffer_dump(uint8_t *pui8Buffer, uint32_t ui32BufferLen);
static void ios_set_up(void);
void inform_host(void);
static void ios_read(uint32_t offset, uint32_t size);
static void ios_send(uint32_t address, uint32_t size);

//*****************************************************************************
//
// IO Slave Main ISR.
//
//*****************************************************************************
void am_ioslave_ios_isr(void)
{
    uint32_t ui32Status;

    //
    // Check to see what caused this interrupt, then clear the bit from the
    // interrupt register.
    //

    am_hal_ios_interrupt_status_get(g_pIOSHandle, false, &ui32Status);
    
    am_hal_ios_interrupt_clear(g_pIOSHandle, ui32Status);

    if (ui32Status & AM_HAL_IOS_INT_FUNDFL)
    {
        am_util_stdio_printf("Hitting underflow for the requested IOS FIFO transfer\r\n");
        // We should never hit this case unless the threshold has been set
        // incorrect, or we are unable to handle the data rate
        // ERROR!
        am_hal_debug_assert_msg(0,
            "Hitting underflow for the requested IOS FIFO transfer.");
    }

    if (ui32Status & AM_HAL_IOS_INT_ERR)
    {
        am_util_stdio_printf("Hitting ERROR case.\r\n");
        // We should never hit this case
        // ERROR!
        am_hal_debug_assert_msg(0,
            "Hitting ERROR case.");
    }

    if (ui32Status & AM_HAL_IOS_INT_FSIZE)
    {
        //
        // Service the I2C slave FIFO if necessary
        //
        am_hal_ios_interrupt_service(g_pIOSHandle, ui32Status);
    }

    if (ui32Status & AM_HAL_IOS_INT_XCMPWR)
    {
        bIomSendComplete = true;
    }
}

//*****************************************************************************
//
// Main function.
//
//*****************************************************************************
int main(void)
{
    // Camera defines
    uint32_t    ui32Err     = HM01B0_ERR_OK;
    uint16_t    ui16ModelId = 0x0000;
    uint8_t     ui8Mode     = 0xFF;

    // I2C Slave defines
    uint8_t  *pui8Packet;
    uint8_t ui8Tag = 1;
    uint8_t ui8Length = 0;

    am_hal_clkgen_control(AM_HAL_CLKGEN_CONTROL_SYSCLK_MAX, 0);

    //
    // Set the default cache configuration
    //
    am_hal_cachectrl_config(&am_hal_cachectrl_defaults);
    am_hal_cachectrl_enable();

    //
    // Configure the board for low power operation.
    //
    am_bsp_low_power_init();

#ifdef AM_BSP_GPIO_CAMERA_HM01B0_DVDDEN
    //
    // Turn on the camera regulator
    //
    am_hal_gpio_pinconfig(AM_BSP_GPIO_CAMERA_HM01B0_DVDDEN, g_AM_HAL_GPIO_OUTPUT_12);
    am_hal_gpio_output_set(AM_BSP_GPIO_CAMERA_HM01B0_DVDDEN);
#endif // AM_BSP_GPIO_CAMERA_HM01B0_DVDDEN

    //
    // Enable the UART print interface at high speed
    //
    am_bsp_uart_printf_enable_custom(&g_sBspUartConfigHS);

    //
    // Clear the terminal and print the banner.
    //
    am_util_stdio_terminal_clear();
    am_util_stdio_printf("This is the Combined HM01B0 and I2C File Program for\r\n");
    am_util_stdio_printf("transferring data from the Sparkfun Edge to the\r\n");
    am_util_stdio_printf("STM32 NUCLEO64 board\r\n");
    am_util_stdio_printf("HM01B0 Pins\r\n");
    am_util_stdio_printf(" SCL:\tPin %d\r\n",  s_HM01B0Cfg.ui8PinSCL);
    am_util_stdio_printf(" SDA:\tPin %d\r\n",  s_HM01B0Cfg.ui8PinSDA);
    am_util_stdio_printf(" MCLK:\tPin %d\r\n",  s_HM01B0Cfg.ui32CTimerOutputPin);
    am_util_stdio_printf(" VSYNC:\tPin %d\r\n", s_HM01B0Cfg.ui8PinVSYNC);
    am_util_stdio_printf(" HSYNC\tPin %d\r\n",  s_HM01B0Cfg.ui8PinHSYNC);
    am_util_stdio_printf(" PCLK:\tPin %d\r\n",  s_HM01B0Cfg.ui8PinPCLK);
    am_util_stdio_printf(" D0:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD0);
    am_util_stdio_printf(" D1:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD1);
    am_util_stdio_printf(" D2:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD2);
    am_util_stdio_printf(" D3:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD3);
    am_util_stdio_printf(" D4:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD4);
    am_util_stdio_printf(" D5:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD5);
    am_util_stdio_printf(" D6:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD6);
    am_util_stdio_printf(" D7:\tPin %d\r\n",    s_HM01B0Cfg.ui8PinD7);

    // LEDS
    // am_bsp_psLEDs[0] = Red    (46)
    // am_bsp_psLEDs[1] = Blue   (37)
    // am_bsp_psLEDs[2] = Green  (44)
    // am_bsp_psLEDs[3] = Yellow (47)
    am_hal_gpio_output_clear(1);
    am_hal_gpio_output_clear(38);
    am_hal_gpio_output_clear(36);
    am_hal_gpio_output_clear(3);

    am_util_stdio_printf("Turning on the LEDs\r\n");
    am_hal_gpio_output_set(1);
    am_hal_gpio_output_set(38);
    am_hal_gpio_output_set(am_bsp_psLEDs[0].ui32GPIONumber);
    am_hal_gpio_output_set(am_bsp_psLEDs[1].ui32GPIONumber);
    am_hal_gpio_output_set(am_bsp_psLEDs[2].ui32GPIONumber);
    am_hal_gpio_output_set(am_bsp_psLEDs[3].ui32GPIONumber);

    am_util_delay_ms(3000);

    am_util_stdio_printf("Turning off the LEDs\r\n");
    am_hal_gpio_output_clear(1);
    am_hal_gpio_output_clear(38);
    am_hal_gpio_output_clear(am_bsp_psLEDs[0].ui32GPIONumber);
    am_hal_gpio_output_clear(am_bsp_psLEDs[1].ui32GPIONumber);
    am_hal_gpio_output_clear(am_bsp_psLEDs[2].ui32GPIONumber);
    am_hal_gpio_output_clear(am_bsp_psLEDs[3].ui32GPIONumber);

    ios_set_up();

    //
    // Enable interrupts so we can receive messages from the boot host.
    //
    am_hal_interrupt_master_enable();

//     boost_mode_enable(true);

//     hm01b0_power_up(&s_HM01B0Cfg);

//     // todo: check the delay time to just fit the spec.
//     am_util_delay_ms(1);

//     hm01b0_mclk_enable(&s_HM01B0Cfg);

//     // todo: check the delay time to just fit the spec.
//     am_util_delay_ms(1);

//     hm01b0_init_if(&s_HM01B0Cfg);

//     hm01b0_get_modelid(&s_HM01B0Cfg, &ui16ModelId);

//     am_util_stdio_printf("HM01B0 Model ID 0x%04X\r\n", ui16ModelId);
      
//     hm01b0_init_system(&s_HM01B0Cfg, (hm_script_t *)sHM01B0InitScript, sizeof(sHM01B0InitScript)/sizeof(hm_script_t));

// #ifdef DEMO_HM01B0_TEST_MODE_ENABLE
//     am_util_stdio_printf("HM01B0 Enable walking 1s test mode\r\n");
//     hm01b0_test_walking1s(&s_HM01B0Cfg);
// #else
//     hm01b0_cal_ae(&s_HM01B0Cfg, 10, s_ui8FrameBuffer, sizeof(s_ui8FrameBuffer));
// #endif

    while(1)
    {
//         hm01b0_ae_cfg_t sAECfg;

//         hm01b0_get_mode(&s_HM01B0Cfg, &ui8Mode);

//         am_util_stdio_printf("HM01B0 current mode %d\r\n", ui8Mode);

//         ui32Err = hm01b0_get_ae(&s_HM01B0Cfg, &sAECfg);
//         am_util_stdio_printf("AE convergance(0x%02X) TargetMean 0x%02X, ConvergeInTh 0x%02X, AEMean 0x%02X\r\n", ui32Err, sAECfg.ui8AETargetMean, sAECfg.ui8ConvergeInTh, sAECfg.ui8AEMean);

//         hm01b0_cmd_update(&s_HM01B0Cfg);

//         hm01b0_set_mode(&s_HM01B0Cfg, HM01B0_REG_MODE_SELECT_STREAMING_NFRAMES, 1);

//         hm01b0_blocking_read_oneframe(&s_HM01B0Cfg, s_ui8FrameBuffer, sizeof(s_ui8FrameBuffer));

// #ifdef DEMO_HM01B0_TEST_MODE_ENABLE
//         hm01b0_test_walking1s_check_data_sanity(s_ui8FrameBuffer, sizeof(s_ui8FrameBuffer), 10);
//         am_util_delay_ms(3000);
// #endif

// #ifdef DEMO_HM01B0_FRAMEBUFFER_DUMP_ENABLE
//         framebuffer_dump(s_ui8FrameBuffer, sizeof(s_ui8FrameBuffer));
// #endif
//         memset(s_ui8FrameBuffer, 0x00, sizeof(s_ui8FrameBuffer));

//         // give some time for user to stop the external itm logging.
//         am_util_delay_ms(5000);
    
        uint32_t ui32IntStatus = am_hal_interrupt_master_disable();
        if (bIomSendComplete)
        {
            // Enable the interrupts
            am_hal_interrupt_master_set(ui32IntStatus);
            // bIomSendComplete = false;
            pui8Packet = (uint8_t *) am_hal_ios_pui8LRAM;
            am_util_stdio_printf("pui8Packet = %d", pui8Packet);
            if (AM_IOSTEST_CMD_START_DATA == pui8Packet[IOM_DATA_TAG])
            {
                // Host wants to start data transmit
                // Respond the ACK
                *((uint8_t *) am_hal_ios_pui8LRAM) = AM_IOSTEST_CMD_ACK_DATA;
                inform_host();
            }
            else if (AM_IOSTEST_CMD_STOP_DATA == pui8Packet[IOM_DATA_TAG])
            {
                break;
            }
            else if (ui8Tag == pui8Packet[IOM_DATA_TAG])
            {
                ui8Length = pui8Packet[IOM_DATA_TAG];
                // Init buffer
                g_pIosSendBuf[IOM_DATA_TAG] = ui8Tag;
                g_pIosSendBuf[IOM_DATA_LENGTH] = ui8Length;
                for (uint8_t i = IOM_DATA_VALUE; i < AM_IOS_LRAM_SIZE_MAX; i++)
                {
                    g_pIosSendBuf[i] = INBUFFER_EMPTY;
                }
                // Read data sent from IOM
                ios_read(0, ui8Length);
                // Reply data to IOM
                ios_send(0, ui8Length);
                ui8Tag++;
                // Notify the host
                inform_host();
            }
        }
        // if (bIomSendComplete)
        // {
        //     // Enable the interrupts
        //     am_hal_interrupt_master_set(ui32IntStatus);
        //     bIomSendComplete = false;
        //     pui8Packet = (uint8_t *) am_hal_ios_pui8LRAM;
        //     if (AM_IOSTEST_CMD_START_DATA == pui8Packet[IOM_DATA_TAG])
        //     {
        //         // Host wants to start data transmit
        //         // Respond the ACK
        //         *((uint8_t *) am_hal_ios_pui8LRAM) = AM_IOSTEST_CMD_ACK_DATA;
        //         inform_host();
        //     }
        //     else if (AM_IOSTEST_CMD_STOP_DATA == pui8Packet[IOM_DATA_TAG])
        //     {
        //         break;
        //     }
        //     else if (ui8Tag == pui8Packet[IOM_DATA_TAG])
        //     {
        //         ui8Length = pui8Packet[IOM_DATA_TAG];
        //         // Init buffer
        //         g_pIosSendBuf[IOM_DATA_TAG] = ui8Tag;
        //         g_pIosSendBuf[IOM_DATA_LENGTH] = ui8Length;
        //         for (uint8_t i = IOM_DATA_VALUE; i < AM_IOS_LRAM_SIZE_MAX; i++)
        //         {
        //             g_pIosSendBuf[i] = INBUFFER_EMPTY;
        //         }
        //         // Read data sent from IOM
        //         ios_read(0, ui8Length);
        //         // Reply data to IOM
        //         ios_send(0, ui8Length);
        //         ui8Tag++;
        //         // Notify the host
        //         inform_host();
        //     }

        // }
        else
        {
            // Enable the interrupts
            am_hal_interrupt_master_set(ui32IntStatus);
        }

    }

    hm01b0_deinit_if(&s_HM01B0Cfg);

    hm01b0_mclk_disable(&s_HM01B0Cfg);

    hm01b0_power_down(&s_HM01B0Cfg);

    boost_mode_enable(false);

    //
    // Loop forever.
    //
    while (1)
    {
        //
        // Go to Deep Sleep.
        //
        am_hal_sysctrl_sleep(AM_HAL_SYSCTRL_SLEEP_DEEP);
    }
}

//*****************************************************************************
//
// Helper Functions
//
//*****************************************************************************

// GPIO ISR
void
am_gpio_isr(void)
{
    if (s_HM01B0Cfg.pfnGpioIsr)
        s_HM01B0Cfg.pfnGpioIsr();
}

// frame buffer dump
void framebuffer_dump(uint8_t *pui8Buffer, uint32_t ui32BufferLen)
{
    am_util_stdio_printf("+++ frame +++");

    for (uint32_t ui32Idx = 0; ui32Idx < ui32BufferLen; ui32Idx++)
    {
        if ((ui32Idx & 0xF) == 0x00)
        {
            am_util_stdio_printf("\r\n0x%08X ", ui32Idx);
            // this delay is to let itm have time to flush out data.
            am_util_delay_ms(1);
        }

        am_util_stdio_printf("%02X ", *(pui8Buffer + ui32Idx));
    }

    am_util_stdio_printf("\r\n--- frame ---\r\n");
    am_util_delay_ms(1);
}

// burst mode enable
void boost_mode_enable(bool bEnable){
    am_hal_burst_avail_e          eBurstModeAvailable;
    am_hal_burst_mode_e           eBurstMode;

    // Check that the Burst Feature is available.
    if (AM_HAL_STATUS_SUCCESS == am_hal_burst_mode_initialize(&eBurstModeAvailable)){
        if (AM_HAL_BURST_AVAIL == eBurstModeAvailable){
            am_util_stdio_printf("Apollo3 Burst Mode is Available\r\n");
        }
        else{
            am_util_stdio_printf("Apollo3 Burst Mode is Not Available\r\n");
            while(1){};
        }
    }
    else{
        am_util_stdio_printf("Failed to Initialize for Burst Mode operation\r\n");
    }

    // Make sure we are in "Normal" mode.
    if (AM_HAL_STATUS_SUCCESS == am_hal_burst_mode_disable(&eBurstMode)){
        if (AM_HAL_NORMAL_MODE == eBurstMode){
            am_util_stdio_printf("Apollo3 operating in Normal Mode (48MHz)\r\n");
        }
    }
    else{
        am_util_stdio_printf("Failed to Disable Burst Mode operation\r\n");
    }

    // Put the MCU into "Burst" mode.
    if (bEnable)
    {
        if (AM_HAL_STATUS_SUCCESS == am_hal_burst_mode_enable(&eBurstMode)){
            if (AM_HAL_BURST_MODE == eBurstMode){
                am_util_stdio_printf("Apollo3 operating in Burst Mode (96MHz)\r\n");
            }
        }
        else{
            am_util_stdio_printf("Failed to Enable Burst Mode operation\r\n");
        }
    }
}

//*****************************************************************************
//
// Configure the I2C slave.
//
//*****************************************************************************
static void ios_set_up(void)
{
    // Configure I2C interface
    am_bsp_ios_pins_enable(0, AM_HAL_IOS_USE_I2C);
    
    // Configure the IOS interface and LRAM structure
    am_hal_ios_initialize(0, &g_pIOSHandle);
    am_hal_ios_power_ctrl(g_pIOSHandle, AM_HAL_SYSCTRL_WAKE, false);
    am_hal_ios_configure(g_pIOSHandle, &g_sIOSI2cConfig);

    // Clear out any IOS register-access interrupts that may be active, and
    // enable interrupts for the registers we're interesting in
    am_hal_ios_interrupt_clear(g_pIOSHandle, AM_HAL_IOS_INT_ALL);
    am_hal_ios_interrupt_enable(g_pIOSHandle, AM_HAL_IOS_INT_ERR | AM_HAL_IOS_INT_FSIZE);
#ifdef TEST_IOINTCTL
    am_hal_ios_interrupt_enable(g_pIOSHandle, AM_HAL_IOS_INT_IOINTW);
#endif
#ifdef TEST_IOS_XCMP_INT
    am_hal_ios_interrupt_enable(g_pIOSHandle, AM_HAL_IOS_XCMP_INT);
#endif

    // Set the bit in the NVIC to accept interrupts from the IO Slave
    NVIC_EnableIRQ(IOSLAVE_IRQn);

    // Set up the IOSINT interrupt pin
    // am_hal_gpio_pinconfig(4, g_AM_BSP_GPIO_ENABLE);
    for (uint8_t i = 0; i < 8; i++)
    {
        am_hal_ios_pui8LRAM[0x78 + i] = ROBUFFER_INIT;
    }
}

// Inform host of new data available to read
void inform_host(void)
{
    uint32_t ui32Arg = HANDSHAKE_IOS_TO_IOM;

    // Update FIFOCTR for host to read
    am_hal_ios_control(g_pIOSHandle, AM_HAL_IOS_REQ_FIFO_UPDATE_CTR, NULL);

    // Interrupt the host
    am_hal_ios_control(g_pIOSHandle, AM_HAL_IOS_REQ_HOST_INTSET, &ui32Arg);
}

// Receive data from host and prepare the loop back data
static void ios_read(uint32_t offset, uint32_t size)
{
    uint32_t i;
    uint8_t readByte;

    // Read only supported from LRAM
    for (i = 0; i + IOM_DATA_VALUE < size; i++)
    {
        readByte = am_hal_ios_pui8LRAM[offset + IOM_DATA_VALUE + i];

        // Read data and prepare to be sent back after processing
        g_pIosSendBuf[IOM_DATA_VALUE + i] = readByte ^ TEST_XOR_BYTE;
    }
}

// Send data to host (IOM)
static void ios_send(uint32_t address, uint32_t size)
{
    // Send data using the LRAM
    while (size--)
    {
        am_hal_ios_pui8LRAM[address + size] = g_pIosSendBuf[size];
    }
}