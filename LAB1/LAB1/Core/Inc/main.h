/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
/* USER CODE BEGIN Private defines */
#define ROW_1_PORT			GPIOA
#define ROW_1_PIN			GPIO_PIN_0
#define ROW_2_PORT			GPIOA
#define ROW_2_PIN			GPIO_PIN_1
#define ROW_3_PORT			GPIOA
#define ROW_3_PIN			GPIO_PIN_2
#define ROW_4_PORT			GPIOA
#define ROW_4_PIN			GPIO_PIN_3
#define ROW_5_PORT			GPIOA
#define ROW_5_PIN			GPIO_PIN_4
#define ROW_6_PORT			GPIOA
#define ROW_6_PIN			GPIO_PIN_5
#define ROW_7_PORT			GPIOA
#define ROW_7_PIN			GPIO_PIN_6
#define ROW_8_PORT			GPIOA
#define ROW_8_PIN			GPIO_PIN_7

#define COL_1_PORT			GPIOA
#define COL_1_PIN			GPIO_PIN_8
#define COL_2_PORT			GPIOA
#define COL_2_PIN			GPIO_PIN_9
#define COL_3_PORT			GPIOA
#define COL_3_PIN			GPIO_PIN_10
#define COL_4_PORT			GPIOA
#define COL_4_PIN			GPIO_PIN_11
#define COL_5_PORT			GPIOA
#define COL_5_PIN			GPIO_PIN_12
#define COL_6_PORT			GPIOA
#define COL_6_PIN			GPIO_PIN_13
#define COL_7_PORT			GPIOA
#define COL_7_PIN			GPIO_PIN_14
#define COL_8_PORT			GPIOA
#define COL_8_PIN			GPIO_PIN_15

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
