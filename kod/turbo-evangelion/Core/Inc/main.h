/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32h5xx_hal.h"

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
#define IR2_Pin GPIO_PIN_13
#define IR2_GPIO_Port GPIOC
#define JOY1_Pin GPIO_PIN_5
#define JOY1_GPIO_Port GPIOC
#define JOY2_Pin GPIO_PIN_0
#define JOY2_GPIO_Port GPIOB
#define JOY3_Pin GPIO_PIN_1
#define JOY3_GPIO_Port GPIOB
#define JOY4_Pin GPIO_PIN_2
#define JOY4_GPIO_Port GPIOB
#define JOY5_Pin GPIO_PIN_10
#define JOY5_GPIO_Port GPIOB
#define FAN_Pin GPIO_PIN_11
#define FAN_GPIO_Port GPIOB
#define IR1_Pin GPIO_PIN_11
#define IR1_GPIO_Port GPIOD
#define IMU_INT2_Pin GPIO_PIN_7
#define IMU_INT2_GPIO_Port GPIOC
#define IMU_INT1_Pin GPIO_PIN_8
#define IMU_INT1_GPIO_Port GPIOC
#define DR2_EN_Pin GPIO_PIN_9
#define DR2_EN_GPIO_Port GPIOA
#define DR1_EN_Pin GPIO_PIN_10
#define DR1_EN_GPIO_Port GPIOA
#define START_LED3_Pin GPIO_PIN_15
#define START_LED3_GPIO_Port GPIOA
#define START_LED2_Pin GPIO_PIN_10
#define START_LED2_GPIO_Port GPIOC
#define START_LED1_Pin GPIO_PIN_11
#define START_LED1_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
