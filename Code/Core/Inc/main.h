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
#include "stm32h7xx_hal.h"

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
#define ERROR_LED_Pin GPIO_PIN_2
#define ERROR_LED_GPIO_Port GPIOE
#define DEBUG_LED_Pin GPIO_PIN_3
#define DEBUG_LED_GPIO_Port GPIOE
#define WRITE_MODE_LED_Pin GPIO_PIN_4
#define WRITE_MODE_LED_GPIO_Port GPIOE
#define FAN_INB_Pin GPIO_PIN_5
#define FAN_INB_GPIO_Port GPIOE
#define FAN_INA_Pin GPIO_PIN_6
#define FAN_INA_GPIO_Port GPIOE
#define POWER_MONITOR_Pin GPIO_PIN_13
#define POWER_MONITOR_GPIO_Port GPIOC
#define PGOOD_Pin GPIO_PIN_0
#define PGOOD_GPIO_Port GPIOA
#define POWER_MONITORA1_Pin GPIO_PIN_1
#define POWER_MONITORA1_GPIO_Port GPIOA
#define USB_PD_GOOD_Pin GPIO_PIN_2
#define USB_PD_GOOD_GPIO_Port GPIOA
#define W6300_LNK_Pin GPIO_PIN_4
#define W6300_LNK_GPIO_Port GPIOA
#define W6300_SPD_Pin GPIO_PIN_6
#define W6300_SPD_GPIO_Port GPIOA
#define W6300_DPXn_Pin GPIO_PIN_7
#define W6300_DPXn_GPIO_Port GPIOA
#define W6300_ACT_Pin GPIO_PIN_4
#define W6300_ACT_GPIO_Port GPIOC
#define W6300_ACT_EXTI_IRQn EXTI4_IRQn
#define W6300_COL_Pin GPIO_PIN_5
#define W6300_COL_GPIO_Port GPIOC
#define W6300_COL_EXTI_IRQn EXTI9_5_IRQn
#define W6300_INT_Pin GPIO_PIN_12
#define W6300_INT_GPIO_Port GPIOE
#define W6300_INT_EXTI_IRQn EXTI15_10_IRQn
#define W6300_RST_Pin GPIO_PIN_13
#define W6300_RST_GPIO_Port GPIOE
#define USB_HS_CHECK_Pin GPIO_PIN_14
#define USB_HS_CHECK_GPIO_Port GPIOE
#define USB3343_RST_Pin GPIO_PIN_15
#define USB3343_RST_GPIO_Port GPIOE
#define FDCAN1_RESET_Pin GPIO_PIN_14
#define FDCAN1_RESET_GPIO_Port GPIOB
#define FDCAN2_RESET_Pin GPIO_PIN_15
#define FDCAN2_RESET_GPIO_Port GPIOB
#define Ethernet_RESET_Pin GPIO_PIN_8
#define Ethernet_RESET_GPIO_Port GPIOD
#define USB_RESET_Pin GPIO_PIN_9
#define USB_RESET_GPIO_Port GPIOD
#define Wi_Fi_RESET_Pin GPIO_PIN_10
#define Wi_Fi_RESET_GPIO_Port GPIOD
#define USB_TX_LED_Pin GPIO_PIN_11
#define USB_TX_LED_GPIO_Port GPIOD
#define USB_RX_LED_Pin GPIO_PIN_14
#define USB_RX_LED_GPIO_Port GPIOD
#define Ethernet_TX_LED_Pin GPIO_PIN_15
#define Ethernet_TX_LED_GPIO_Port GPIOD
#define Ethernet_RX_LED_Pin GPIO_PIN_6
#define Ethernet_RX_LED_GPIO_Port GPIOC
#define BOOTMODE_Pin GPIO_PIN_7
#define BOOTMODE_GPIO_Port GPIOC
#define SDMMC_CHECK_Pin GPIO_PIN_8
#define SDMMC_CHECK_GPIO_Port GPIOA
#define Speaker_IN1_Pin GPIO_PIN_9
#define Speaker_IN1_GPIO_Port GPIOA
#define Speaker_IN2_Pin GPIO_PIN_10
#define Speaker_IN2_GPIO_Port GPIOA
#define FDCAN2_TX_LED_Pin GPIO_PIN_0
#define FDCAN2_TX_LED_GPIO_Port GPIOD
#define FDCAN2_RX_LED_Pin GPIO_PIN_1
#define FDCAN2_RX_LED_GPIO_Port GPIOD
#define FDCAN1_TX_LED_Pin GPIO_PIN_3
#define FDCAN1_TX_LED_GPIO_Port GPIOD
#define FDCAN1_RX_LED_Pin GPIO_PIN_4
#define FDCAN1_RX_LED_GPIO_Port GPIOD
#define SDMMC_WRITE_LED_Pin GPIO_PIN_6
#define SDMMC_WRITE_LED_GPIO_Port GPIOB
#define SDMMC_READ_LED_Pin GPIO_PIN_7
#define SDMMC_READ_LED_GPIO_Port GPIOB
#define FW_UART_TXF_Pin GPIO_PIN_0
#define FW_UART_TXF_GPIO_Port GPIOE
#define FW_UART_RXF_Pin GPIO_PIN_1
#define FW_UART_RXF_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
