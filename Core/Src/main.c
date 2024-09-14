/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "eink_nfc.h"
#include "st25dv.h"
#include "EPD_2in13d.h"
#include "DEV_Config.h"
#include "GUI_Paint_new.h"
#include "imagedata.h"
#include <stdlib.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//Logo picture 60x60 bitmap data
#define LOGO_MAX_LENGTH		480
#define Imagesize 			((EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1)) * EPD_HEIGHT
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
ST25DV_Object_t st25Obj={0};
EINK_NFC_TAGINFO_OBJ eink_nfc_taginfo={0};

uint8_t BlackImage[Imagesize]={0};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  	// Initialization ST25DV
  	I2C1_Init_Reg();
	ST25DV_SetEH_MODE(&st25Obj.Ctx, ST25DV_EH_ACTIVE_AFTER_BOOT);
	ST25DV_EH_MODE_STATUS value_eh_mode;
	ST25DV_GetEH_MODE(&st25Obj.Ctx, &value_eh_mode);

	// GPO configuration
	ST25DV_SetGPO_ENABLE(&st25Obj.Ctx, 0);
	ST25DV_SetGPO_RFWRITE(&st25Obj.Ctx,0);
	//ST25DV_SetGPO_FIELDCHANGE(&st25Obj.Ctx, 0);
	ST25DV_SetGPO_RFUSERSTATE(&st25Obj.Ctx, 0);

	// Init EPD
	if(EPD_Init() != 0) {
		printf("e-Paper init failed\r\n");
	}

		// Clear EPD display
		// Init image buffer
		EPD_Clear();
		printf("size = %d\r\n", 	 EPD_WIDTH / 8 * EPD_HEIGHT);
		printf("Paint_NewImage\r\n");
		Paint_NewImage(BlackImage, EPD_WIDTH, EPD_HEIGHT, 270, WHITE);
		Paint_SelectImage(BlackImage);
		Paint_Clear(WHITE);
    	// Select image buffer
		Paint_SelectImage(BlackImage);
		//Clear buffer. Set 0xFF for every byte
		Paint_Clear(WHITE);

		// Reading data from st25dv
		uint8_t dataBuff[850]={0};
		ST25DV_ReadData(&st25Obj, dataBuff, 0, 850);
		// Parse data from st25dv to variables in struct
		EINK_NFC_Parser(&eink_nfc_taginfo, dataBuff);

		//Draw Logo
		Paint_DrawBitMap_Paste(eink_nfc_taginfo.logo_bitmap, 155, 1, 60, 60, BLACK);

		//Draw prices
		char strPrice[16];
		// Draw EUR price
		sprintf(strPrice,"EUR%s",eink_nfc_taginfo.priceEUR_txt);
		Paint_DrawString_EN(65, 0, 						 strPrice, &Font12, WHITE, BLACK);
		// Draw USD price
		sprintf(strPrice,"USD%s",eink_nfc_taginfo.priceUSD_txt);
		Paint_DrawString_EN(65, 5 + Font12.Height,		 strPrice, &Font12, WHITE, BLACK);
		// Draw PLN price
		sprintf(strPrice,"PLN%s",eink_nfc_taginfo.pricePLN_txt);
		Paint_DrawString_EN(65, (5 + Font12.Height)*2, 	 strPrice, &Font12, WHITE, BLACK);
		// Draw GPB price
		sprintf(strPrice,"GBP%s",eink_nfc_taginfo.priceGBP_txt);
		Paint_DrawString_EN(65, (5 + Font12.Height)*3, 	 strPrice, &Font12, WHITE, BLACK);

		// Draw washing images
		uint8_t position_x=25;
		Paint_DrawBitMap_Paste(eink_nfc_taginfo.washing_bitmap,		 position_x, 73, 35, 35, BLACK);
		position_x+=35;
		Paint_DrawBitMap_Paste(eink_nfc_taginfo.bleaching_bitmap, 	 position_x, 73, 35, 35, BLACK);
		position_x+=35;
		Paint_DrawBitMap_Paste(eink_nfc_taginfo.drying_bitmap, 		 position_x, 73, 35, 35, BLACK);
		position_x+=35;
		Paint_DrawBitMap_Paste(eink_nfc_taginfo.ironing_bitmap, 	 position_x, 73, 35, 35, BLACK);
		position_x+=35;
		Paint_DrawBitMap_Paste(eink_nfc_taginfo.professional_bitmap, position_x, 73, 35, 35, BLACK);

		// Generate QR code and draw
		Paint_DrawQR_Paste(eink_nfc_taginfo.QR_txt,0,0);
		//Rotate and Draw size
		char strSize[4];
		Paint_SetRotate(ROTATE_180);
		Paint_DrawString_EN(0, 0, 				 "size:", &Font8, WHITE, BLACK);
		sprintf(strSize,"%s",eink_nfc_taginfo.size_txt);
		Paint_DrawString_EN(0, Font8.Height, 	 strSize, &Font16, WHITE, BLACK);
		EPD_Display(BlackImage);
      printf("Goto Sleep mode...\r\n");
      // Enter EPD in sleep mode
      EPD_Sleep();
      // Enable STANDBY mode
      HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
      __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);

      HAL_PWR_EnterSTANDBYMode();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void I2C1_Init_Reg(void){
	ST25DV_IO_t IO;

	 IO.Init         = (ST25DV_Init_Func) MX_I2C1_Init;
	 IO.DeInit       = (ST25DV_DeInit_Func)HAL_I2C_DeInit;
	 IO.IsReady      = (ST25DV_IsReady_Func)HAL_I2C_IsDeviceReady;
	 IO.Read         = (ST25DV_Read_Func)I2C1_ReadReg16;
	 IO.Write        = (ST25DV_Write_Func)I2C1_WriteReg16;
	 IO.GetTick      = (ST25DV_GetTick_Func)HAL_GetTick;
	ST25DV_RegisterBusIO(&st25Obj, &IO);

}
int32_t  I2C1_ReadReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length)
{
  int32_t ret = 0;

  if (HAL_I2C_Mem_Read(&hi2c1, DevAddr, Reg, I2C_MEMADD_SIZE_16BIT, pData, Length, HAL_I2C_STATE_TIMEOUT) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) != HAL_I2C_ERROR_AF)
    {
      ret =  -102;
    }
    else
    {
      ret =  -4;
    }
  }
  return ret;
}
int32_t I2C1_WriteReg16(uint16_t DevAddr, uint16_t Reg, uint8_t *pData, uint16_t Length)
{
  int32_t ret = 0;

  if (HAL_I2C_Mem_Write(&hi2c1, DevAddr, Reg, I2C_MEMADD_SIZE_16BIT, pData, Length, HAL_I2C_STATE_TIMEOUT) != HAL_OK)
  {
    if (HAL_I2C_GetError(&hi2c1) == HAL_I2C_ERROR_AF)
    {
      ret = -102;
    }
    else
    {
      ret =  -4;
    }
  }
  return ret;
}
/* USER CODE END 4 */

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
