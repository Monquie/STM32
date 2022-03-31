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
#define RED 	0
#define AMBER 	1
#define GREEN	2

#define BUTTON_0 			GPIO_PIN_0
#define BUTTON_1 			GPIO_PIN_1
#define BUTTON_2 			GPIO_PIN_2

#define PORT_RED1 		GPIOB
#define PORT_RED2 		GPIOB
#define PORT_AMBER1 	GPIOB
#define PORT_AMBER2 	GPIOB
#define PORT_GREEN1 	GPIOB
#define PORT_GREEN2 	GPIOB

#define PIN_RED1 		GPIO_PIN_3
#define PIN_GREEN1 		GPIO_PIN_4
#define PIN_AMBER1 		GPIO_PIN_5
#define PIN_RED2 		GPIO_PIN_6
#define PIN_GREEN2 		GPIO_PIN_7
#define PIN_AMBER2 		GPIO_PIN_8

#define EN0_PORT		GPIOB
#define EN0_PIN			GPIO_PIN_9
#define EN1_PORT		GPIOB
#define EN1_PIN			GPIO_PIN_10
#define EN2_PORT		GPIOB
#define EN2_PIN			GPIO_PIN_11
#define EN3_PORT		GPIOB
#define EN3_PIN			GPIO_PIN_12

#define SEG_A_1_PORT		GPIOA
#define SEG_A_1_PIN			GPIO_PIN_1
#define SEG_B_1_PORT		GPIOA
#define SEG_B_1_PIN			GPIO_PIN_2
#define SEG_C_1_PORT		GPIOA
#define SEG_C_1_PIN			GPIO_PIN_3
#define SEG_D_1_PORT		GPIOA
#define SEG_D_1_PIN			GPIO_PIN_4
#define SEG_E_1_PORT		GPIOA
#define SEG_E_1_PIN			GPIO_PIN_5
#define SEG_F_1_PORT		GPIOA
#define SEG_F_1_PIN			GPIO_PIN_6
#define SEG_G_1_PORT		GPIOA
#define SEG_G_1_PIN			GPIO_PIN_7

#define SEG_A_2_PORT		GPIOA
#define SEG_A_2_PIN			GPIO_PIN_8
#define SEG_B_2_PORT		GPIOA
#define SEG_B_2_PIN			GPIO_PIN_9
#define SEG_C_2_PORT		GPIOA
#define SEG_C_2_PIN			GPIO_PIN_10
#define SEG_D_2_PORT		GPIOA
#define SEG_D_2_PIN			GPIO_PIN_11
#define SEG_E_2_PORT		GPIOA
#define SEG_E_2_PIN			GPIO_PIN_12
#define SEG_F_2_PORT		GPIOA
#define SEG_F_2_PIN			GPIO_PIN_13
#define SEG_G_2_PORT		GPIOA
#define SEG_G_2_PIN			GPIO_PIN_14



/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
