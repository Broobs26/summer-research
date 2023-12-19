#include "ArduCAMCustom.h"
#include "ov2640_regs.h"

extern I2C_HandleTypeDef hi2c1;
extern SPI_HandleTypeDef hspi2;
extern UART_HandleTypeDef huart2;

//TODO: Write a function to read the image buffer into the STM32's memory
//TODO: Finish copying over necessary methods from spi.c

byte sensor_model = 0;
byte sensor_addr = 0;
byte m_fmt = BMP;
uint32_t length = 0;
uint8_t is_header = false ;

static const uint8_t OV2640_addr = 0x60;

void ArduCAM_Init(void)
{
	wrSensorReg8_8(0xff, 0x01);
	wrSensorReg8_8(0x12, 0x80);
	if(m_fmt == JPEG)
	{
		wrSensorRegs8_8(OV2640_JPEG_INIT);
		wrSensorRegs8_8(OV2640_YUV422);
		wrSensorRegs8_8(OV2640_JPEG);
		wrSensorReg8_8(0xff, 0x01);
		wrSensorReg8_8(0x15, 0x00);
		wrSensorRegs8_8(OV2640_320x240_JPEG);
	}
	else
	{
		wrSensorRegs8_8(OV2640_QVGA);
	}
}

void set_format(byte fmt)
{
	if (fmt == BMP)
		m_fmt = BMP;
	else
		m_fmt = JPEG;
}

//TODO: Implement image capture and transfer function
//TODO: Figure out bounds of the image, as well as why it is 1032/2056 FIFO size with cover ON/OFF
void StartImageCapture(uint8_t *fb)
{
	flush_fifo();
	clear_fifo_flag();
	start_capture();
	while(!get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK)){;}
	length = read_fifo_length();
	printf("Length of the FIFO: %ld\r\n", length);
	CS_Low();
	set_fifo_burst();
	uint8_t VH, VL;
	uint32_t count = 0;
	uint32_t count2 = 0;
	VH = SPI_ReadWriteByte(0x00);
	VL = SPI_ReadWriteByte(0x00);
	printf("Bool VH: %d\r\n", (VH != 0xff));
	printf("Bool VL: %d\r\n", (VL != 0xd9));
	count = count + 2;
	printf("VH: 0x%x, VL: 0x%x\r\n", VH, VL);
//	while (true)
//	{
//		VH = SPI_ReadWriteByte(0x00);
//		VL = SPI_ReadWriteByte(0x00);
//		count = count + 2;
//		count2 = count2 + 2;
//		printf("0x%x 0x%x ", VH, VL);
//		if (((VH == 0xff) && (VL == 0xd9)) || ((VH == 0xd9) && (VL == 0xff))) {break;}
//		if (count2 == 44)
//		{
//			count2 = 0;
//			printf("\r\n");
//		}
//		if (count == length){break;}
//	}
	printf("VH: 0x%x, VL: 0x%x ", VH, VL);
	printf("Count: %ld\r\n", count);
	CS_High();
}

uint8_t SPI_ReadWriteByte(uint8_t TxData)
{
	uint8_t tx_buf[1];
	uint8_t rx_buf[1];
	tx_buf[0] = TxData;
	rx_buf[0] = 0x00;
	if (HAL_SPI_TransmitReceive(&hspi2, tx_buf, rx_buf, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		printf("SPI_ReadWriteByte() Transmit + Receive Error!\r\n");
		Error_Handler();
	}
	return rx_buf[0];
}

uint8_t bus_read(int address)
{
	uint8_t spi_buf[1];
    spi_buf[0] = address;
    CS_Low();
    if (HAL_SPI_Transmit(&hspi2, spi_buf, 1, HAL_MAX_DELAY) != HAL_OK)
    {
    	printf("bus_read() Transmit Error!\r\n");
    	printf("Reading Address: 0x%x\r\n", address);
    	Error_Handler();
    }
    spi_buf[0] = 0x00;
    if (HAL_SPI_Receive(&hspi2, spi_buf, 1, HAL_MAX_DELAY) != HAL_OK)
    {
    	printf("bus_read() Receive Error!\r\n");
    	printf("Reading Address: 0x%x\r\n", address);
    	Error_Handler();
    }
    CS_High();
    return spi_buf[0];
}

uint8_t bus_write(int address,int value)
{
	uint8_t spi_buf[2];
	spi_buf[0] = address;
	spi_buf[1] = value;

	CS_Low();
	if (HAL_SPI_Transmit(&hspi2, spi_buf, 2, HAL_MAX_DELAY) != HAL_OK)
	{
		printf("bus_write() Transmit Error!\r\n");
		printf("Writing Address: 0x%x, Data: 0x%x\r\n", address, value);
		Error_Handler();
	}
	CS_High();
	return 1;
}

uint8_t read_reg(uint8_t addr)
{
	uint8_t data;
	data = bus_read(addr & 0x7F);
	return data;
}


void write_reg(uint8_t addr, uint8_t data)
{
	 bus_write(addr | 0x80, data);
}

uint8_t read_fifo(void)
{
	uint8_t data;
	data = bus_read(SINGLE_FIFO_READ);
	return data;
}

//TODO: Test this function
void set_fifo_burst()
{
	SPI_ReadWriteByte(BURST_FIFO_READ);
//	SPI2_ReadWriteByte(BURST_FIFO_READ);
}

void flush_fifo(void)
{
	write_reg(ARDUCHIP_FIFO, FIFO_CLEAR_MASK);
}

void start_capture(void)
{
	write_reg(ARDUCHIP_FIFO, FIFO_START_MASK);
}

void clear_fifo_flag(void )
{
	write_reg(ARDUCHIP_FIFO, FIFO_CLEAR_MASK);
}

uint32_t read_fifo_length(void)
{
	uint32_t len1,len2,len3,len=0;
	len1 = read_reg(FIFO_SIZE1);
    len2 = read_reg(FIFO_SIZE2);
    len3 = read_reg(FIFO_SIZE3) & 0x7f;
    len = ((len3 << 16) | (len2 << 8) | len1) & 0x07fffff;
	return len;
}

//Set corresponding bit
void set_bit(uint8_t addr, uint8_t bit)
{
	uint8_t temp;
	temp = read_reg(addr);
	write_reg(addr, temp | bit);
}
//Clear corresponding bit
void clear_bit(uint8_t addr, uint8_t bit)
{
	uint8_t temp;
	temp = read_reg(addr);
	write_reg(addr, temp & (~bit));
}

//Get corresponding bit status
uint8_t get_bit(uint8_t addr, uint8_t bit)
{
  uint8_t temp;
  temp = read_reg(addr);
  temp = temp & bit;
  return temp;
}

//Set ArduCAM working mode
//MCU2LCD_MODE: MCU writes the LCD screen GRAM
//CAM2LCD_MODE: Camera takes control of the LCD screen
//LCD2MCU_MODE: MCU read the LCD screen GRAM
void set_mode(uint8_t mode)
{
  switch (mode)
  {
    case MCU2LCD_MODE:
      write_reg(ARDUCHIP_MODE, MCU2LCD_MODE);
      break;
    case CAM2LCD_MODE:
      write_reg(ARDUCHIP_MODE, CAM2LCD_MODE);
      break;
    case LCD2MCU_MODE:
      write_reg(ARDUCHIP_MODE, LCD2MCU_MODE);
      break;
    default:
      write_reg(ARDUCHIP_MODE, MCU2LCD_MODE);
      break;
  }
}


void OV2640_set_JPEG_size(uint8_t size)
{
	switch(size)
	{
		case OV2640_160x120:
			wrSensorRegs8_8(OV2640_160x120_JPEG);
			break;
		case OV2640_176x144:
			wrSensorRegs8_8(OV2640_176x144_JPEG);
			break;
		case OV2640_320x240:
			wrSensorRegs8_8(OV2640_320x240_JPEG);
			break;
		case OV2640_352x288:
	  	wrSensorRegs8_8(OV2640_352x288_JPEG);
			break;
		case OV2640_640x480:
			wrSensorRegs8_8(OV2640_640x480_JPEG);
			break;
		case OV2640_800x600:
			wrSensorRegs8_8(OV2640_800x600_JPEG);
			break;
		case OV2640_1024x768:
			wrSensorRegs8_8(OV2640_1024x768_JPEG);
			break;
		case OV2640_1280x1024:
			wrSensorRegs8_8(OV2640_1280x1024_JPEG);
			break;
		case OV2640_1600x1200:
			wrSensorRegs8_8(OV2640_1600x1200_JPEG);
			break;
		default:
			wrSensorRegs8_8(OV2640_320x240_JPEG);
			break;
	}
}

byte wrSensorReg8_8(int regID, int regDat)
{
	uint8_t buf[2];
	buf[0] = regID;
	buf[1] = regDat;
	if (HAL_I2C_Master_Transmit(&hi2c1, OV2640_addr, buf, 2, HAL_MAX_DELAY) != HAL_OK)
	{
		printf("wrSensorReg8_8() Transmit Error!\r\n");
		printf("regID: 0x%x, regDat: 0x%x\r\n", regID, regDat);
		Error_Handler();
	}
	return 0;
}

byte rdSensorReg8_8(uint8_t regID, uint8_t* regDat)
{
	uint8_t addrBuf[1];
	addrBuf[0] = regID;
	if (HAL_I2C_Master_Transmit(&hi2c1, OV2640_addr, addrBuf, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		printf("rdSensorReg8_8() Transmit Failure\r\n");
		Error_Handler();
	}
	if (HAL_I2C_Master_Receive(&hi2c1, OV2640_addr, regDat, 1, HAL_MAX_DELAY) != HAL_OK)
	{
		printf("rdSensorReg8_8 Receive Failure\r\n");
		Error_Handler();
	}
	return 0;
}

//I2C Array Write 8bit address, 8bit data
int wrSensorRegs8_8(const struct sensor_reg reglist[])
{
  int err = 0;
  uint16_t reg_addr = 0;
  uint16_t reg_val = 0;
  const struct sensor_reg *next = reglist;
  while ((reg_addr != 0xff) | (reg_val != 0xff))
  {
    reg_addr = next->reg;
    reg_val = next->val;
    err = wrSensorReg8_8(reg_addr, reg_val);
 //   delay_us(400);
    next++;
  }

  return err;
}
