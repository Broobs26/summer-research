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
//#include "tensorflow/lite/micro/kernels/all_ops_resolver.h"
//#include "tensorflow/lite/micro/micro_error_reporter.h"
//#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
//#include "tensorflow/lite/micro/micro_interpreter.h"
//#include "tensorflow/lite/schema/schema_generated.h"
//#include "tensorflow/lite/version.h"
//
//#include "../Models/model.h"
//
//#include "tensorflow/lite/micro/testing/micro_test.h"

#include "./TF/main_functions1.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ADDR_VREFINT_CAL ((uint16_t*) VREFINT_CAL_ADDR)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc3;
RTC_HandleTypeDef hrtc;
UART_HandleTypeDef huart2;

float voltage = 0.0;
__IO uint16_t uhADCxConvertedValue = 0;
uint16_t ADC_max_binary = ((1<<12)-1);
float ADC_ref_voltage = 3.3;
float ADC_sys_voltage = 0.0;
RTC_HandleTypeDef RTCHandle;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void PeriphCommonClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC3_Init(void);
static void MX_RTC_Init(void);

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

/* Configure the peripherals common clocks */
  PeriphCommonClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_ADC3_Init();
  MX_RTC_Init();

  // Clears Terminal Upon Reset
  printf("\033[2J");
  printf("Reset!\r\n");


  if (HAL_ADC_Start(&hadc3) != HAL_OK)
  {
	  printf("hadc3 Start Error\r\n");
	  Error_Handler();
  }

  if (HAL_ADC_Start(&hadc1) != HAL_OK)
  {
	  printf("hadc1 Start Error\r\n");
	  Error_Handler();
  }

  if (HAL_ADC_PollForConversion(&hadc3, 10) != HAL_OK)
  {
	  printf("hadc3 PollForConversion Error\r\n");
	  Error_Handler();
  }
  else
  {
	  uint32_t HAL_val = HAL_ADC_GetValue(&hadc3);
	  printf("HAL_ADC_GetValue: %ld\r\n", HAL_val);
      printf("hadc3 Number: %f\r\n", (HAL_val / float(ADC_max_binary)) * ADC_ref_voltage);
  }

  if (HAL_ADC_PollForConversion(&hadc1, 10) != HAL_OK)
  {
	  printf("hadc1 PollForConversion Error\r\n");
	  Error_Handler();
  }
  else
  {
	  uint32_t HAL_val = HAL_ADC_GetValue(&hadc1);
	  printf("HAL_ADC_GetValue: %ld\r\n", HAL_val);
      printf("hadc1 Number: %f\r\n", (HAL_val / float(ADC_max_binary)) * ADC_ref_voltage);
  }

  printf("adc_ref_internal_read(): %f\r\n", adc_ref_internal_read());

  // Setup the Neural Network
  setup1();

//  tflite::MicroErrorReporter micro_error_reporter;
//  tflite::ErrorReporter* error_reporter = &micro_error_reporter;
//  const tflite::Model* model = ::tflite::GetModel(g_model);
//  if (model->version() != TFLITE_SCHEMA_VERSION) {
//	  TF_LITE_REPORT_ERROR(error_reporter,
//		"Model provided is schema version %d not equal "
//		"to supported version %d. \n",
//		model->version(), TFLITE_SCHEMA_VERSION);
//  }
//
//  printf("Model Version: %ld, TFLITE SCHEMA Version: %d\r\n", model->version(), TFLITE_SCHEMA_VERSION);
//
//  tflite::ops::micro::AllOpsResolver resolver;
//
//  const int tensor_arena_size = 2 * 1024;
//  uint8_t tensor_arena[tensor_arena_size] __attribute__ ((aligned(16)));
//
//  tflite::MicroInterpreter interpreter(model, resolver, tensor_arena, tensor_arena_size, error_reporter);
//  interpreter.AllocateTensors();
//
//  TfLiteTensor* input = interpreter.input(0);
//
//  input->data.f[0] = 0.;
//
//  TfLiteStatus invoke_status = interpreter.Invoke();
//  if (invoke_status != kTfLiteOk)
//  {
//    printf("Invoke Failed\r\n");
//  }
//
//  TfLiteTensor* output = interpreter.output(0);
//
//  float value = output->data.f[0];
//
//  printf("Output value: %f\r\n", value);

  int image_index = 0;

  /* Infinite loop */
  while (1)
  {
	  main_single_event(image_index, 3.3);
	  image_index++;
	  if (image_index == 4)
	  {
		  image_index = 0;
		  HAL_Delay(15000);
	  }
	  HAL_SuspendTick();
	  HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
	  //HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	  HAL_Delay(5000);
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief Peripherals Common Clock Configuration
  * @retval None
  */
void PeriphCommonClock_Config(void)
{
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the peripherals clock
  */
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSI;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 8;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
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
  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
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
  sConfig.Channel = ADC_CHANNEL_16;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC3_Init(void)
{
  ADC_ChannelConfTypeDef sConfig = {0};

  /** Common config
  */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc3.Init.Resolution = ADC_RESOLUTION_12B;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc3.Init.LowPowerAutoWait = DISABLE;
  hadc3.Init.ContinuousConvMode = DISABLE;
  hadc3.Init.NbrOfConversion = 1;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc3.Init.DMAContinuousRequests = DISABLE;
  hadc3.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc3.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
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
  hrtc.Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enable the RTC Tamper 2
  */
  sTamper.Tamper = RTC_TAMPER_2;
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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
		//ADC_sys_voltage *= 4.0f;
		// compensate
		//ADC_sys_voltage *= (5.11/4.01f);
	}
	return ADC_sys_voltage;
}

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

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_ResumeTick();
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
  printf("ERROR!\r\n");
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
