/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
#include "tensorflow/lite/micro/kernels/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"

#include "../Models/model.h"
#include "tensorflow/lite/micro/testing/micro_test.h"

#include "./TF/main_functions_custom.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ADDR_VREFINT_CAL ((uint16_t*) VREFINT_CAL_ADDR)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc3;
RTC_HandleTypeDef hrtc;
UART_HandleTypeDef huart1;

static uint32_t LCD_X_Size = 0;
static uint32_t LCD_Y_Size = 0;
static uint32_t CameraResX = VGA_RES_X;
static uint32_t CameraResY = VGA_RES_Y;

__IO uint32_t camera_frame_ready = 0;
__IO uint32_t lcd_frame_ready = 0;

__IO uint16_t uhADCxConvertedValue = 0;
uint16_t ADC_max_binary = ((1<<16)-1);
float ADC_ref_voltage = 3.3;
float ADC_sys_voltage = 0.0;
RTC_HandleTypeDef RTCHandle;

uint32 stm32iplBuffer[STM32IPL_INT_BUFFER_SIZE];

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC3_Init(void);
static void MX_RTC_Init(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);
void UTILS_Init(void);
void DISPLAY_Init(void);
void LCD_TestDisplay(void);
void CAMERA_Init(void);
static void DMA2D_ConvertFrameToARGB8888(void *pSrc, void *pDst, uint32_t xsize, uint32_t ysize);
static void DMA2D_TransferCompleteCallback(DMA2D_HandleTypeDef *hdma2d);
void stop_mode1(void);
void stop_mode2(void);

/* Private user code ---------------------------------------------------------*/
/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	MPU_Config();

	CPU_CACHE_Enable();

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Configure the peripherals common clocks */
    PeriphCommonClock_Config();

    __HAL_RCC_HSEM_CLK_ENABLE();


    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_ADC3_Init();
    MX_RTC_Init();
    MX_USART1_UART_Init();

    // Clears Terminal Upon Reset
    printf("\033[2J");
    printf("Reset!\r\n");

    // Initialize buttons, joystick, LEDs
    UTILS_Init();

    // Initialize LCD Display
    DISPLAY_Init();

    // Initialize Camera
    CAMERA_Init();

    // LED to show INIT is completed
    BSP_LED_On(LED_ORANGE);

    // Instantiate the IPL
    STM32Ipl_InitLib(stm32iplBuffer, STM32IPL_INT_BUFFER_SIZE);

    // FUNCTIONS TO BE USED TO CONVERT
    // STM32Ipl_Downscale
    // STM32Ipl_ConvertRev
    // Finish Image Conversion
    // Camera Buffer to image_t

    // Setup the Neural Network
    setup1();

    // Defining Variables
    JOYPin_TypeDef joyState;
    int32_t err;
    uint32_t start1;
    uint32_t stop1;
    uint32_t delta1;
    //int sample_idx = 3;
    image_t camera_img;
	image_t inter_img;
	image_t final_img;

    float target_voltage = 3.9;
    float sys_vol;
    stop_mode2_duration(200);
    sys_vol = adc_ref_internal_read();
    stop_mode2_duration(200);
    sys_vol = adc_ref_internal_read();
    printf("voltage=%.2f, target=%.2f :)\r\n", sys_vol, target_voltage);

//    tflite::MicroErrorReporter micro_error_reporter;
//    tflite::ErrorReporter* error_reporter = &micro_error_reporter;
//
//    const tflite::Model* model = ::tflite::GetModel(g_model);
//    if (model->version() != TFLITE_SCHEMA_VERSION) {
//  	  TF_LITE_REPORT_ERROR(error_reporter,
//  	    "Model provided is schema version %d not equal "
//  	    "to supported version %d. \n",
//  		model->version(), TFLITE_SCHEMA_VERSION);
//    }
//
//    printf("Model Version: %ld, TFLITE SCHEMA Version: %d\r\n", model->version(), TFLITE_SCHEMA_VERSION);
//
//    tflite::ops::micro::AllOpsResolver resolver;
//
//    const int tensor_arena_size = 2 * 1024;
//    uint8_t tensor_arena[tensor_arena_size] __attribute__ ((aligned(16)));
//
//    tflite::MicroInterpreter interpreter(model, resolver, tensor_arena, tensor_arena_size, error_reporter);
//    interpreter.AllocateTensors();
//
//    TfLiteTensor* input = interpreter.input(0);
//
//    input->data.f[0] = 0.;
//
//    TfLiteStatus invoke_status = interpreter.Invoke();
//    if (invoke_status != kTfLiteOk)
//    {
//  	  printf("Invoke Failed\r\n");
//    }
//
//    TfLiteTensor* output = interpreter.output(0);
//
//    float value = output->data.f[0];
//
//    printf("Output value: %f\r\n", value);

    /* Infinite loop */
    while (1)
    {
    	joyState = (JOYPin_TypeDef) BSP_JOY_GetState(JOY1, 0);
    	switch (joyState)
    	{
    		case JOY_UP:
    			printf("Voltage = %f\r\n", adc_ref_internal_read());
    			HAL_Delay(1000);
    			break;
    		case JOY_DOWN:
    			start1 = HAL_GetTick();

    			//sample_idx = 2;
    			//main_single_event(sample_idx, 0.0);

    			stop1 = HAL_GetTick();

    			delta1 = stop1 - start1;
    			printf("Delta: %ld\r\n", delta1);
    			HAL_Delay(1000);
    			break;
    		case JOY_LEFT:

    			UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
    			UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
    			UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLUE);
    			UTIL_LCD_SetFont(&Font16);

    			err = BSP_CAMERA_Start(0, (uint8_t *)CAMERA_FRAME_BUFFER, CAMERA_MODE_SNAPSHOT);
    			if (err != BSP_ERROR_NONE)
    			{
    				printf("Camera Start Error No: %ld\r\n", err);
    				Error_Handler();
    			}
    			while(camera_frame_ready == 0){}

    			BSP_CAMERA_Stop(0);

    			DMA2D_ConvertFrameToARGB8888((uint32_t *)(CAMERA_FRAME_BUFFER), (uint32_t *)(LCD_FRAME_BUFFER), CameraResX, CameraResY);

    			while(lcd_frame_ready == 0){}

    			HAL_Delay(1500);

    			if (BSP_PB_GetState(BUTTON_WAKEUP) == 1)
    			{
					camera_img.data = (uint8_t *)CAMERA_FRAME_BUFFER;
					camera_img.w = VGA_RES_X;
					camera_img.h = VGA_RES_Y;
					camera_img.bpp = IMAGE_BPP_RGB565;

					inter_img.data = (uint8_t *)INTER_FRAME_BUFFER;
					inter_img.w = 28;
					inter_img.h = 28;
					inter_img.bpp = IMAGE_BPP_RGB565;

					final_img.data = (uint8_t *)FINAL_FRAME_BUFFER;
					final_img.w = 28;
					final_img.h = 28;
					final_img.bpp = IMAGE_BPP_GRAYSCALE;

					STM32Ipl_Downscale(&camera_img, &inter_img, false);
					STM32Ipl_ConvertRev(&inter_img, &final_img, false);

	    			for (int x = 0; x < 28; x++)
	    			{
	    				for (int y = 0; y < 28; y++)
	    				{
	    					printf("%3d ", final_img.data[(x * 28) + y]);
	    				}
	    				printf("\r\n");
	    			}

					main_single_event_image(final_img, 0.0);

					printf("Image Processing Complete\r\n");
    			}
    			else
    			{
    				printf("Take a new photo\r\n");
    			}

    			UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

    			break;
    		case JOY_RIGHT:
    			printf("RIGHT\r\n");
    			HAL_Delay(1000);
    			break;
    		case JOY_SEL:
    			printf("PUSHED\r\n");

    			UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
    			UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
    			UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLUE);
    			UTIL_LCD_SetFont(&Font16);

    			err = BSP_CAMERA_Start(0, (uint8_t *)CAMERA_FRAME_BUFFER, CAMERA_MODE_SNAPSHOT);
    			if (err != BSP_ERROR_NONE)
    			{
    				printf("Camera Start Error No: %ld\r\n", err);
    				Error_Handler();
    			}

    			while(camera_frame_ready == 0){}

    			BSP_CAMERA_Stop(0);

    			DMA2D_ConvertFrameToARGB8888((uint32_t *)(CAMERA_FRAME_BUFFER), (uint32_t *)(LCD_FRAME_BUFFER), CameraResX, CameraResY);

    			while(lcd_frame_ready == 0){}

    			HAL_Delay(1500);

    			UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
    			UTIL_LCD_ClearStringLine(250);
    			UTIL_LCD_DisplayStringAt(0, 250, (uint8_t *)"We HAD an IMAGE!", CENTER_MODE);
    			break;
    		default:
    			break;
    	}
    }
}


/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 400000000 (Cortex-M7 CPU Clock)
 *            HCLK(Hz)                       = 200000000 (Cortex-M4 CPU, Bus matrix Clocks)
 *            AHB Prescaler                  = 2
 *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
 *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
 *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
 *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 5
 *            PLL_N                          = 160
 *            PLL_P                          = 2
 *            PLL_Q                          = 4
 *            PLL_R                          = 2
 *            VDD(V)                         = 3.3
 *            Flash Latency(WS)              = 4
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /*!< Supply configuration update enable */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;

  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    Error_Handler();
  }

/* Select PLL as system clock source and configure  bus clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_PCLK1 | \
                                 RCC_CLOCKTYPE_PCLK2  | RCC_CLOCKTYPE_D3PCLK1);

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
  if(ret != HAL_OK)
  {
    Error_Handler();
  }

 /*
  Note : The activation of the I/O Compensation Cell is recommended with communication  interfaces
          (GPIO, SPI, FMC, QSPI ...)  when  operating at  high frequencies(please refer to product datasheet)
          The I/O Compensation Cell activation  procedure requires :
        - The activation of the CSI clock
        - The activation of the SYSCFG clock
        - Enabling the I/O Compensation Cell : setting bit[0] of register SYSCFG_CCCSR
 */

  /*activate CSI clock mondatory for I/O Compensation Cell*/
  __HAL_RCC_CSI_ENABLE() ;

  /* Enable SYSCFG clock mondatory for I/O Compensation Cell */
  __HAL_RCC_SYSCFG_CLK_ENABLE() ;

  /* Enables the I/O Compensation Cell */
  HAL_EnableCompensationCell();
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInitStruct.PLL2.PLL2M = 2;
  PeriphClkInitStruct.PLL2.PLL2N = 12;
  PeriphClkInitStruct.PLL2.PLL2P = 2;
  PeriphClkInitStruct.PLL2.PLL2Q = 2;
  PeriphClkInitStruct.PLL2.PLL2R = 2;
  PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_3;
  PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOMEDIUM;
  PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_16B;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  sConfig.OffsetSignedSaturation = DISABLE;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief ADC3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC3_Init(void)
{

  /* USER CODE BEGIN ADC3_Init 0 */

  /* USER CODE END ADC3_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC3_Init 1 */

  /* USER CODE END ADC3_Init 1 */

  /** Common config
  */
  hadc3.Instance = ADC3;
  hadc3.Init.Resolution = ADC_RESOLUTION_16B;
  hadc3.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc3.Init.LowPowerAutoWait = DISABLE;
  hadc3.Init.ContinuousConvMode = DISABLE;
  hadc3.Init.NbrOfConversion = 1;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc3.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;
  hadc3.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc3.Init.LeftBitShift = ADC_LEFTBITSHIFT_NONE;
  hadc3.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  sConfig.OffsetSignedSaturation = DISABLE;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC3_Init 2 */

  /* USER CODE END ADC3_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TamperTypeDef sTamper = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */

  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable the RTC Tamper 1
  */
  sTamper.Tamper = RTC_TAMPER_1;
  sTamper.Trigger = RTC_TAMPERTRIGGER_RISINGEDGE;
  sTamper.NoErase = RTC_TAMPER_ERASE_BACKUP_ENABLE;
  sTamper.MaskFlag = RTC_TAMPERMASK_FLAG_DISABLE;
  sTamper.Filter = RTC_TAMPERFILTER_DISABLE;
  sTamper.SamplingFrequency = RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV32768;
  sTamper.PrechargeDuration = RTC_TAMPERPRECHARGEDURATION_1RTCCLK;
  sTamper.TamperPullUp = RTC_TAMPER_PULLUP_ENABLE;
  sTamper.TimeStampOnTamperDetection = RTC_TIMESTAMPONTAMPERDETECTION_ENABLE;
  if (HAL_RTCEx_SetTamper(&hrtc, &sTamper) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();

  /*Configure GPIO pin : CEC_CK_MCO1_Pin */
  GPIO_InitStruct.Pin = CEC_CK_MCO1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(CEC_CK_MCO1_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
/**
  * @brief  Configure the MPU attributes as Write Through for External SDRAM.
  * @note   The Base Address is 0xD0000000 .
  *         The Configured Region Size is 32MB because same as SDRAM size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;

  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU as Strongly ordered for not defined regions */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x00;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Configure the MPU attributes as WT for SDRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = SDRAM_DEVICE_ADDR;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER1;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
* @brief  CPU L1-Cache enable.
* @param  None
* @retval None
*/
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

// Initializes all of the peripherals
void UTILS_Init(void)
{
    // LEDs
	BSP_LED_Init(LED_GREEN);
	BSP_LED_Init(LED_ORANGE);
	BSP_LED_Init(LED_RED);
	BSP_LED_Init(LED_BLUE);

	// Joystick
	BSP_JOY_Init(JOY1, JOY_MODE_GPIO, JOY_ALL);

	// Push Buttons
	BSP_PB_Init(BUTTON_WAKEUP, BUTTON_MODE_GPIO);
}

// Initializes the LCD Display
void DISPLAY_Init(void)
{
	// Initialize the LCD
	int32_t error = BSP_LCD_Init(0, LCD_ORIENTATION_LANDSCAPE);
	if (error != BSP_ERROR_NONE)
	{
		printf("Display Init Error No: %ld\r\n", error);
		Error_Handler();
	}

	// Set the Drivers
	UTIL_LCD_SetFuncDriver(&LCD_Driver);
	UTIL_LCD_SetLayer(0);

	BSP_LCD_GetXSize(0, &LCD_X_Size);
	BSP_LCD_GetYSize(0, &LCD_Y_Size);

	printf("LCD Size\r\n");
	printf("X: %ld, Y: %ld\r\n", LCD_X_Size, LCD_Y_Size);

	// Display a quick test
	LCD_TestDisplay();
}

// Testing the LCD Display
void LCD_TestDisplay(void)
{
	// Simple Test LCD Display
	UTIL_LCD_Clear(UTIL_LCD_COLOR_BLUE);
	UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
	UTIL_LCD_SetFont(&Font24);
	UTIL_LCD_DisplayStringAt(0, LINE(2), (uint8_t *)"TESTING!", CENTER_MODE);
	UTIL_LCD_DisplayStringAt(0, LINE(3), (uint8_t *)"WORKING! :)", CENTER_MODE);
	HAL_Delay(2500);
	UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
}

// Initializing the Camera
void CAMERA_Init(void)
{
	// Make sure the camera is powered off before startings
	BSP_CAMERA_PwrDown(0);

	// Initialize the camera
	int32_t error = BSP_CAMERA_Init(0, CAMERA_R640x480, CAMERA_PF_RGB565);
	if (error != BSP_ERROR_NONE)
	{
		printf("Camera Init Error No: %ld\r\n", error);
		Error_Handler();
	}

	HAL_Delay(1000);
}

/**
  * @brief  Converts a line to an ARGB8888 pixel format.
  * @param  pSrc: Pointer to source buffer
  * @param  pDst: Output color
  * @param  ColorMode: Input color mode
  * @retval None
  */
static void DMA2D_ConvertFrameToARGB8888(void *pSrc, void *pDst, uint32_t xsize, uint32_t ysize)
{
  uint32_t xPos, yPos, destination;

  /* Calculate the destination transfer address */
  xPos = (LCD_X_Size  - xsize)/2;
  yPos = (LCD_Y_Size  - ysize)/2;

  /* Enable DMA2D clock */
  __HAL_RCC_DMA2D_CLK_ENABLE();

  /* Configure the DMA2D Mode, Color Mode and output offset */
  hlcd_dma2d.Init.Mode         = DMA2D_M2M_PFC;
  hlcd_dma2d.Init.ColorMode    = DMA2D_OUTPUT_ARGB8888; /* Output color out of PFC */
  hlcd_dma2d.Init.OutputOffset = LCD_X_Size - xsize;
  hlcd_dma2d.Init.AlphaInverted = DMA2D_REGULAR_ALPHA;  /* No Output Alpha Inversion*/
  hlcd_dma2d.Init.RedBlueSwap   = DMA2D_RB_REGULAR;     /* No Output Red & Blue swap */

  /* DMA2D Callbacks Configuration */
  hlcd_dma2d.XferCpltCallback  = DMA2D_TransferCompleteCallback;

  /* Foreground Configuration */
  hlcd_dma2d.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hlcd_dma2d.LayerCfg[1].InputAlpha = 0xFF; /* fully opaque */
  hlcd_dma2d.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
  hlcd_dma2d.LayerCfg[1].InputOffset = 0;
  hlcd_dma2d.LayerCfg[1].RedBlueSwap = DMA2D_RB_REGULAR; /* No ForeGround Red/Blue swap */
  hlcd_dma2d.LayerCfg[1].AlphaInverted = DMA2D_REGULAR_ALPHA; /* No ForeGround Alpha inversion */

  hlcd_dma2d.Instance = DMA2D;

  /* DMA2D Initialization */
  if(HAL_DMA2D_Init(&hlcd_dma2d) == HAL_OK)
  {
    if(HAL_DMA2D_ConfigLayer(&hlcd_dma2d, 1) != HAL_OK)
    {
      printf("HAL_DMA2D_ConfigLayer Error\r\n");
      Error_Handler();
    }
  }
  else
  {
	printf("HAL_DMA2D_Init Error\r\n");
    Error_Handler();
  }

  /* Calculate the destination transfer address */
  xPos = (LCD_X_Size  - xsize)/2;
  yPos = (LCD_Y_Size  - ysize)/2;

  destination = (uint32_t)pDst + (yPos * LCD_X_Size + xPos) * ARGB8888_BYTE_PER_PIXEL;

  /* Starts the DMA2D transfer */
  if(HAL_DMA2D_Start_IT(&hlcd_dma2d, (uint32_t)pSrc, destination, xsize, ysize) != HAL_OK)
  {
	printf("HAL_DMA2D_Start_IT Error\r\n");
    Error_Handler();
  }
}

/**
  * @brief  Camera line event callback
  * @param  None
  * @retval None
  */
void BSP_CAMERA_FrameEventCallback(uint32_t Instance)
{
  camera_frame_ready = 1;
}

/**
 * @brief  DMA2D Transfer completed callback
 * @param  hdma2d: DMA2D handle.
 * @retval None
 */
static void DMA2D_TransferCompleteCallback(DMA2D_HandleTypeDef *hdma2d)
{
  lcd_frame_ready = 1;
}

float adc_ref_internal_read(void)
{
	uint16_t VREFINT_CAL, VREFINT_DATA;
	VREFINT_CAL = *ADDR_VREFINT_CAL;
	float vref_int_voltage = 0.0;

	// Start the conversion process for hadc3
	if (HAL_ADC_Start(&hadc3) != HAL_OK)
	{
		printf("hadc3 Start Error\r\n");
		Error_Handler();
	}

	// Start the conversion process for hadc1
	if (HAL_ADC_Start(&hadc1) != HAL_OK)
	{
		printf("hadc1 Start Error\r\n");
		Error_Handler();
	}

	// Wait for the end of the conversation for hadc3
	if (HAL_ADC_PollForConversion(&hadc3, 10) != HAL_OK)
	{
		printf("hadc3 PollForConversion Error\r\n");
		Error_Handler();
	}
	else
	{
		// Read converted value
		VREFINT_DATA = HAL_ADC_GetValue(&hadc3);

		// Convert result from 16 bit value to voltage dimension (mV unit)
		// Vref = 3.3 V
		vref_int_voltage = (VREFINT_DATA / (float)ADC_max_binary) * ADC_ref_voltage;
	}

	// Wait for the end of the conversation for hadc1s
	if (HAL_ADC_PollForConversion(&hadc1, 10) != HAL_OK)
	{
		printf("hadc1 PollForConversion Error\r\n");
		Error_Handler();
	}
	else
	{
		// ADC conversion completed
		// Get converted value of the regular channel
		uhADCxConvertedValue = HAL_ADC_GetValue(&hadc1);
		ADC_sys_voltage = 3.3f * (float)VREFINT_CAL * uhADCxConvertedValue / ((float)VREFINT_DATA * ADC_max_binary);
		// resistor divide
		ADC_sys_voltage *= 4.0f;
		// compensate
		ADC_sys_voltage *= (5.11/4.01f);
	}
	return ADC_sys_voltage;
}

#define D3SRAM_ADDRESS        0x38000000
#define D3SRAM_DATA           0x30313233
#define D3SRAM_ERASE_DATA     0xFFFFFFFF
#define D3SRAM_SIZE           0x4000 /* 16 KB */
#define PWR_WAKEUP_PIN_FLAGS  (PWR_WAKEUP_FLAG1 | PWR_WAKEUP_FLAG2 | PWR_WAKEUP_FLAG3 | \
                               PWR_WAKEUP_FLAG4 | PWR_WAKEUP_FLAG5 | PWR_WAKEUP_FLAG6)
static void SRAM_WriteData()
{
  uint32_t SRAM_Index;

  /* Erase  D3 SRAM */
  for( SRAM_Index = 0; SRAM_Index < D3SRAM_SIZE ; SRAM_Index++)
  {
   *(__IO uint32_t*)(D3SRAM_ADDRESS + (SRAM_Index * 4)) = D3SRAM_ERASE_DATA ;
  }

  /* Fill  D3 SRAM */
  for( SRAM_Index = 0; SRAM_Index < D3SRAM_SIZE ; SRAM_Index++)
  {
   *(__IO uint32_t*)(D3SRAM_ADDRESS + (SRAM_Index * 4)) = D3SRAM_DATA;
  }
}

/**
  * @brief  Check data from D3 SRAM memory
  * @param  None
  * @retval None
  */
static void SRAM_CheckData()
{
  uint32_t SRAM_Index;

  /* Chedk  D3 SRAM data */
  for( SRAM_Index = 0; SRAM_Index < D3SRAM_SIZE ; SRAM_Index++)
  {
    if ( *(__IO uint32_t*)(D3SRAM_ADDRESS + (SRAM_Index * 4)) != D3SRAM_DATA)
    {
      Error_Handler();
    }
  }
}

//static void CPU_CACHE_Clean(void)
//{
//  /* Clean D-Cache */
//  SCB_CleanDCache();
//}

#define RTC_ASYNCH_PREDIV    0x7F
#define RTC_SYNCH_PREDIV     0x0130
void RTC_Config(void)
{
  /* Configure RTC */
  RTCHandle.Instance = RTC;

  /* Set the RTC time base to 1s */
  /* Configure RTC prescaler and RTC data registers as follow:
    - Hour Format     = Format 24
    - Asynch Prediv   = Value according to source clock
    - Synch Prediv    = Value according to source clock
    - OutPut          = Output Disable
    - OutPutPolarity  = High Polarity
    - OutPutType      = Open Drain */
  RTCHandle.Init.HourFormat = RTC_HOURFORMAT_24;
  RTCHandle.Init.AsynchPrediv = RTC_ASYNCH_PREDIV;
  RTCHandle.Init.SynchPrediv = RTC_SYNCH_PREDIV;
  RTCHandle.Init.OutPut = RTC_OUTPUT_DISABLE;
  RTCHandle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  RTCHandle.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if(HAL_RTC_Init(&RTCHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
}

void stop_mode1(void)
{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
//	HAL_Delay(1);
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);

	/* Check and handle if D1 domain was resumed from StandBy mode */
	if(__HAL_PWR_GET_FLAG(PWR_FLAG_SB_D1) != RESET)
	{
		/* Check D3SRAM data */
		SRAM_CheckData();

		/* Clear Standby flag */
		__HAL_PWR_CLEAR_FLAG(PWR_CPU_FLAGS);
	}

	/* Configure RTC */
	RTC_Config();

	/* Insert 3 seconds delay */
//	HAL_Delay(3000);

	/* The Following Wakeup sequence is highly recommended prior to each Standby mode entry
	mainly  when using more than one wakeup source this is to not miss any wakeup event.
	- Disable all used wakeup sources,
	- Clear all related wakeup flags,
	- Re-enable all used wakeup sources,
	- Enter the Standby mode.
	 */
	/* Disable all used wakeup sources*/
	HAL_RTCEx_DeactivateWakeUpTimer(&RTCHandle);

	/* Clear all related wakeup flags */
	HAL_PWREx_ClearWakeupFlag(PWR_WAKEUP_PIN_FLAGS);

	/* Re-enable all used wakeup sources*/
	/* ## Setting the Wake up time ############################################*/
	/* RTC Wakeup Interrupt Generation:
	the wake-up counter is set to its maximum value to yield the longuest
	stand-by time to let the current reach its lowest operating point.
	The maximum value is 0xFFFF, corresponding to about 33 sec. when
	RTC_WAKEUPCLOCK_RTCCLK_DIV = RTCCLK_Div16 = 16

	Wakeup Time Base = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSI))
	Wakeup Time = Wakeup Time Base * WakeUpCounter
	  = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSI)) * WakeUpCounter
	  ==> WakeUpCounter = Wakeup Time / Wakeup Time Base

	To configure the wake up timer to 5s the WakeUpCounter is set to 0x2710:
	Wakeup Time Base = 16 /(~32.000KHz) = ~0.5 ms
	Wakeup Time = 0.5 ms  * WakeUpCounter
	Therefore, with wake-up counter =  0x2710  = 10,000
	   Wakeup Time =  0,5 ms *  10,000 = 5 sec. */
	HAL_RTCEx_SetWakeUpTimer_IT(&RTCHandle, 0x2710, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

	if(__HAL_PWR_GET_FLAG(PWR_FLAG_SB_D1) == RESET)
	{
		/* Write D3SRAM data */
		SRAM_WriteData();

		/* Before entering Stanby mode make CPU cache clean operation to ensure that data are written in D3SRAM */
//		CPU_CACHE_Clean();

		/* Check written data */
		SRAM_CheckData();

		/* Set LED1 Off to inform the user that the system will enter STOP mode */
//		BSP_LED_Off(LED1);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);

		/* Enter D2 Domain to Standby mode */
		HAL_PWREx_EnterSTANDBYMode(PWR_D2_DOMAIN);

		/* Enter D1 to Standby mode. In this case the system will enter STOP mode since D1
	   is in DSTANDBY mode, D2 is in DSTANDBY and D3 is in DSTOP mode */
		HAL_PWREx_EnterSTANDBYMode(PWR_D1_DOMAIN);
	}

	while(1)
	{
		printf("123\r\n");
	}
}

// sleep ms
void stop_mode1_duration(uint32_t ms)
{
	/* Check and handle if D1 domain was resumed from StandBy mode */
	if(__HAL_PWR_GET_FLAG(PWR_FLAG_SB_D1) != RESET)
	{
		/* Check D3SRAM data */
//		SRAM_CheckData();

		/* Clear Standby flag */
		__HAL_PWR_CLEAR_FLAG(PWR_CPU_FLAGS);
	}

	/* Configure RTC */
	RTC_Config();

	/* Insert 3 seconds delay */
//	HAL_Delay(3000);

	/* The Following Wakeup sequence is highly recommended prior to each Standby mode entry
	mainly  when using more than one wakeup source this is to not miss any wakeup event.
	- Disable all used wakeup sources,
	- Clear all related wakeup flags,
	- Re-enable all used wakeup sources,
	- Enter the Standby mode.
	 */
	/* Disable all used wakeup sources*/
	HAL_RTCEx_DeactivateWakeUpTimer(&RTCHandle);

	/* Clear all related wakeup flags */
	HAL_PWREx_ClearWakeupFlag(PWR_WAKEUP_PIN_FLAGS);

	/* Re-enable all used wakeup sources*/
	/* ## Setting the Wake up time ############################################*/
	/* RTC Wakeup Interrupt Generation:
	the wake-up counter is set to its maximum value to yield the longuest
	stand-by time to let the current reach its lowest operating point.
	The maximum value is 0xFFFF, corresponding to about 33 sec. when
	RTC_WAKEUPCLOCK_RTCCLK_DIV = RTCCLK_Div16 = 16

	Wakeup Time Base = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSI))
	Wakeup Time = Wakeup Time Base * WakeUpCounter
	  = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSI)) * WakeUpCounter
	  ==> WakeUpCounter = Wakeup Time / Wakeup Time Base

	To configure the wake up timer to 5s the WakeUpCounter is set to 0x2710:
	Wakeup Time Base = 16 /(~32.000KHz) = ~0.5 ms
	Wakeup Time = 0.5 ms  * WakeUpCounter
	Therefore, with wake-up counter =  0x2710  = 10,000
	   Wakeup Time =  0,5 ms *  10,000 = 5 sec. */
	uint32_t counts = ms * (0x2710 / 5000);
	HAL_RTCEx_SetWakeUpTimer_IT(&RTCHandle, counts, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

	if(__HAL_PWR_GET_FLAG(PWR_FLAG_SB_D1) == RESET)
	{
		/* Write D3SRAM data */
//		SRAM_WriteData();

		/* Before entering Stanby mode make CPU cache clean operation to ensure that data are written in D3SRAM */
//		CPU_CACHE_Clean();

		/* Check written data */
//		SRAM_CheckData();

		/* Set LED1 Off to inform the user that the system will enter STOP mode */
//		BSP_LED_Off(LED1);
//		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);

		/* Enter D2 Domain to Standby mode */
		HAL_PWREx_EnterSTANDBYMode(PWR_D2_DOMAIN);

		/* Enter D1 to Standby mode. In this case the system will enter STOP mode since D1
	   is in DSTANDBY mode, D2 is in DSTANDBY and D3 is in DSTOP mode */
		HAL_PWREx_EnterSTANDBYMode(PWR_D1_DOMAIN);
	}

	while(1)
	{
		printf("123\r\n");
	}
}

void stop_mode2(void)
{
	/* Configure the RTC */
	RTC_Config();

//	while (1)
//	{
		// read ADC voltage
//		adc_ref_internal_read();
		/* Turn LED1 on */
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);

		/* Insert 5 second delay */
		HAL_Delay(1);

		/* Disable Wakeup Counter */
		HAL_RTCEx_DeactivateWakeUpTimer(&RTCHandle);

		/* ## Setting the Wake up time ############################################*/
		/*  RTC Wakeup Interrupt Generation:
		  Wakeup Time Base = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSE or LSI))
		  Wakeup Time = Wakeup Time Base * WakeUpCounter
		  = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSE or LSI)) * WakeUpCounter
			==> WakeUpCounter = Wakeup Time / Wakeup Time Base

		  To configure the wake up timer to 20s the WakeUpCounter is set to 0x9C40:
		  RTC_WAKEUPCLOCK_RTCCLK_DIV = RTCCLK_Div16 = 16
		  Wakeup Time Base = 16 /(32.000KHz) = 0,5 ms
		  Wakeup Time = 20s = 0,5ms  * WakeUpCounter
		==> WakeUpCounter = 20s/0,5ms = 40000 = 0x9C40 */
		// 5s
//		HAL_RTCEx_SetWakeUpTimer_IT(&RTCHandle, 0x2710, RTC_WAKEUPCLOCK_RTCCLK_DIV16);
		HAL_RTCEx_SetWakeUpTimer_IT(&RTCHandle, 0x9C40, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

		/* Turn LED1 OFF  */
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);

		/* Enter Stop Mode */
		HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
		/* Configures system clock after wake-up from STOP: enable HSE, PLL and select
			PLL as system clock source (HSE and PLL are disabled in STOP mode) */
		//	SYSCLKConfig_STOP();
		/* Configure the system clock */
		SystemClock_Config();

		/* Configure the peripherals common clocks */
		PeriphCommonClock_Config();
//	}
}

// sleep ms
void stop_mode2_duration(uint32_t ms)
{
	/* Configure the RTC */
	RTC_Config();

	/* Disable Wakeup Counter */
	HAL_RTCEx_DeactivateWakeUpTimer(&RTCHandle);

	/* ## Setting the Wake up time ############################################*/
	/*  RTC Wakeup Interrupt Generation:
	  Wakeup Time Base = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSE or LSI))
	  Wakeup Time = Wakeup Time Base * WakeUpCounter
	  = (RTC_WAKEUPCLOCK_RTCCLK_DIV /(LSE or LSI)) * WakeUpCounter
		==> WakeUpCounter = Wakeup Time / Wakeup Time Base

	  To configure the wake up timer to 20s the WakeUpCounter is set to 0x9C40:
	  RTC_WAKEUPCLOCK_RTCCLK_DIV = RTCCLK_Div16 = 16
	  Wakeup Time Base = 16 /(32.000KHz) = 0,5 ms
	  Wakeup Time = 20s = 0,5ms  * WakeUpCounter
	==> WakeUpCounter = 20s/0,5ms = 40000 = 0x9C40 */
	// 5s
	uint32_t counts = ms * (0x2710 / 5000);
//	HAL_RTCEx_SetWakeUpTimer_IT(&RTCHandle, 0x2710, RTC_WAKEUPCLOCK_RTCCLK_DIV16);
	HAL_RTCEx_SetWakeUpTimer_IT(&RTCHandle, counts, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

	/* Enter Stop Mode */
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
	/* Configures system clock after wake-up from STOP: enable HSE, PLL and select
		PLL as system clock source (HSE and PLL are disabled in STOP mode) */
	//	SYSCLKConfig_STOP();
	/* Configure the system clock */
	SystemClock_Config();

	/* Configure the peripherals common clocks */
	PeriphCommonClock_Config();
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
