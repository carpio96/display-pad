/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define led_Pin GPIO_PIN_0
#define led_GPIO_Port GPIOC
#define LCD_RESET_Pin GPIO_PIN_2
#define LCD_RESET_GPIO_Port GPIOC
#define SDIO_CARD_DET_Pin GPIO_PIN_3
#define SDIO_CARD_DET_GPIO_Port GPIOC
#define LCD_D15_Pin GPIO_PIN_0
#define LCD_D15_GPIO_Port GPIOA
#define LCD_D14_Pin GPIO_PIN_1
#define LCD_D14_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LCD_D13_Pin GPIO_PIN_4
#define LCD_D13_GPIO_Port GPIOA
#define LCD_D12_Pin GPIO_PIN_5
#define LCD_D12_GPIO_Port GPIOA
#define LCD_D11_Pin GPIO_PIN_6
#define LCD_D11_GPIO_Port GPIOA
#define CTP_NRST_Pin GPIO_PIN_7
#define CTP_NRST_GPIO_Port GPIOA
#define CTP_NINT_Pin GPIO_PIN_4
#define CTP_NINT_GPIO_Port GPIOC
#define CTP_NWAKE_Pin GPIO_PIN_5
#define CTP_NWAKE_GPIO_Port GPIOC
#define CTP_SCL_Pin GPIO_PIN_10
#define CTP_SCL_GPIO_Port GPIOB
#define LCD_D5_Pin GPIO_PIN_12
#define LCD_D5_GPIO_Port GPIOB
#define LCD_D4_Pin GPIO_PIN_13
#define LCD_D4_GPIO_Port GPIOB
#define LCD_D3_Pin GPIO_PIN_14
#define LCD_D3_GPIO_Port GPIOB
#define LCD_D2_Pin GPIO_PIN_15
#define LCD_D2_GPIO_Port GPIOB
#define LCD_D1_Pin GPIO_PIN_6
#define LCD_D1_GPIO_Port GPIOC
#define LCD_D0_Pin GPIO_PIN_7
#define LCD_D0_GPIO_Port GPIOC
#define LCD_WRITE_Pin GPIO_PIN_9
#define LCD_WRITE_GPIO_Port GPIOC
#define LCD_READ_Pin GPIO_PIN_8
#define LCD_READ_GPIO_Port GPIOA
#define LCD_DC_Pin GPIO_PIN_9
#define LCD_DC_GPIO_Port GPIOA
#define LCD_NCS_Pin GPIO_PIN_10
#define LCD_NCS_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LCD_D6_Pin GPIO_PIN_15
#define LCD_D6_GPIO_Port GPIOA
#define LCD_D7_Pin GPIO_PIN_10
#define LCD_D7_GPIO_Port GPIOC
#define CTP_DATA_Pin GPIO_PIN_12
#define CTP_DATA_GPIO_Port GPIOC
#define LCD_D8_Pin GPIO_PIN_3
#define LCD_D8_GPIO_Port GPIOB
#define LCD_D9_Pin GPIO_PIN_4
#define LCD_D9_GPIO_Port GPIOB
#define LCD_D10_Pin GPIO_PIN_5
#define LCD_D10_GPIO_Port GPIOB
#define LED_B_Pin GPIO_PIN_6
#define LED_B_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_7
#define LED_G_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_8
#define LED_R_GPIO_Port GPIOB
#define Buzzer_Pin GPIO_PIN_9
#define Buzzer_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
