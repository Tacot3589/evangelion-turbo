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
#include "stm32g4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define JOY3_Pin GPIO_PIN_13
#define JOY3_GPIO_Port GPIOC
#define JOY2_Pin GPIO_PIN_14
#define JOY2_GPIO_Port GPIOC
#define JOY1_Pin GPIO_PIN_15
#define JOY1_GPIO_Port GPIOC
#define JOY5_Pin GPIO_PIN_10
#define JOY5_GPIO_Port GPIOG
#define LPUART1_RX_Pin GPIO_PIN_2
#define LPUART1_RX_GPIO_Port GPIOA
#define DRV_CS_2_Pin GPIO_PIN_3
#define DRV_CS_2_GPIO_Port GPIOA
#define VBAT_IN_Pin GPIO_PIN_4
#define VBAT_IN_GPIO_Port GPIOA
#define UART3_RX_Pin GPIO_PIN_10
#define UART3_RX_GPIO_Port GPIOB
#define START_MOD_IR_Pin GPIO_PIN_11
#define START_MOD_IR_GPIO_Port GPIOB
#define START_MOD_IR_EXTI_IRQn EXTI15_10_IRQn
#define DRV_CURRENT_A_Pin GPIO_PIN_12
#define DRV_CURRENT_A_GPIO_Port GPIOB
#define JOY4_Pin GPIO_PIN_6
#define JOY4_GPIO_Port GPIOC
#define OLED_SDA_Pin GPIO_PIN_8
#define OLED_SDA_GPIO_Port GPIOA
#define OLED_SCL_Pin GPIO_PIN_9
#define OLED_SCL_GPIO_Port GPIOA
#define DRV_CS_1_Pin GPIO_PIN_10
#define DRV_CS_1_GPIO_Port GPIOA
#define DRV_PWM_A1_Pin GPIO_PIN_11
#define DRV_PWM_A1_GPIO_Port GPIOA
#define DRV_PWM_A2_Pin GPIO_PIN_12
#define DRV_PWM_A2_GPIO_Port GPIOA
#define LED_BLUE_Pin GPIO_PIN_15
#define LED_BLUE_GPIO_Port GPIOA
#define UART4_RX_Pin GPIO_PIN_10
#define UART4_RX_GPIO_Port GPIOC
#define LED_RED_Pin GPIO_PIN_11
#define LED_RED_GPIO_Port GPIOC
#define LED_GREEN_Pin GPIO_PIN_5
#define LED_GREEN_GPIO_Port GPIOB
#define DRV_PWM_B2_Pin GPIO_PIN_6
#define DRV_PWM_B2_GPIO_Port GPIOB
#define IMU_SDA_Pin GPIO_PIN_7
#define IMU_SDA_GPIO_Port GPIOB
#define IMU_SCL_Pin GPIO_PIN_8
#define IMU_SCL_GPIO_Port GPIOB
#define DRV_PWM_B1_Pin GPIO_PIN_9
#define DRV_PWM_B1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
