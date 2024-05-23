/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define sensorContagem_Pin GPIO_PIN_13
#define sensorContagem_GPIO_Port GPIOC
#define sensorContagem_EXTI_IRQn EXTI15_10_IRQn
#define sensor2_Pin GPIO_PIN_14
#define sensor2_GPIO_Port GPIOC
#define sensor2_EXTI_IRQn EXTI15_10_IRQn
#define sensor3_Pin GPIO_PIN_15
#define sensor3_GPIO_Port GPIOC
#define sensor3_EXTI_IRQn EXTI15_10_IRQn
#define Linha1_Pin GPIO_PIN_12
#define Linha1_GPIO_Port GPIOB
#define Linha2_Pin GPIO_PIN_13
#define Linha2_GPIO_Port GPIOB
#define Linha3_Pin GPIO_PIN_14
#define Linha3_GPIO_Port GPIOB
#define Linha4_Pin GPIO_PIN_15
#define Linha4_GPIO_Port GPIOB
#define Coluna1_Pin GPIO_PIN_8
#define Coluna1_GPIO_Port GPIOA
#define Coluna2_Pin GPIO_PIN_9
#define Coluna2_GPIO_Port GPIOA
#define Coluna3_Pin GPIO_PIN_10
#define Coluna3_GPIO_Port GPIOA
#define Coluna4_Pin GPIO_PIN_11
#define Coluna4_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
