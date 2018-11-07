/* ==========================================================
 * config.h - SDK Configuration file
 * Project : IngeniousThings SDK
 * ----------------------------------------------------------
 * Created on: 2 sept. 2018
 *     Author: Paul Pinault aka Disk91
 * ----------------------------------------------------------
 * Copyright (C) 2018  IngeniousThings and Disk91
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU LESSER General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Lesser Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * ----------------------------------------------------------
 * 
 *
 * ==========================================================
 */

#ifndef IT_SDK_CONFIG_H_
#define IT_SDK_CONFIG_H_

#include <it_sdk/config_defines.h>

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// | SDK SETTING                   | USER SELECTED VALUE                  | SETTING DESCRIPTION                   |
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define ITSDK_PLATFORM 				__PLATFORM_STM32L0x3					// Hardware platform selection
#define ITSDK_DEVICE				__DEVICE_STM32L053R8					// Specific device
#define ITSDK_WITH_UART				( __UART_USART2 | __UART_LPUART1 )		// Use LPUART1 and USART2 for debug
#define ITSDK_WITH_RTC				__RTC_ENABLED							// The Rtc is usd in the firmware
#define ITSDK_WITH_ADC				__ADC_ENABLED							// Use of Adc (includes the structures)
#define ITSDK_WITH_SPI				__SPI_ENABLED							// Use SPI (inludes the strutures)
#define ITSDK_ADC1_PIN				14										// Map the channel for ADC on PIN 14 (PA0)
#define ITSDK_VDD_MV				3300									// VDD value in cV
#define ITSDK_WITH_CLK_ADJUST		0										// The RTC (and wtachdog) is calibrated
#define ITSDK_CLK_CORRECTION		-41										// remove 41 o/oo of the ticks
#define ITSDK_WDG_MS				16000									// WatchDog time out in ms 1 --> 28000 / 0 to disable
#define ITSDK_LOGGER_CONF			0x00F0									// all level on serial1 => USART2 (see logger.c)

#define ITSDK_LOWPOWER_MOD			( __LOWPWR_MODE_STOP \
									| __LOWPWR_MODE_WAKE_RTC \
									| __LOWPWR_MODE_WAKE_LPUART	\
									)										// Mode Stop + wakeup RTC & LPUART + GPIO
#define ITSDK_LOWPOWER_RTC_MS		500										// RTC wake up after 500ms
#define ITSDK_LOWPOWER_GPIO_A_KEEP	(  __LP_GPIO_5  \
									 | __LP_GPIO_2  \
									 | __LP_GPIO_3  \
		                            )										// Keep 5 activ (led) and 2/3 (Usart2)
#define ITSDK_LOWPOWER_GPIO_B_KEEP	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank B are all off
#define ITSDK_LOWPOWER_GPIO_C_KEEP	(   __LP_GPIO_4 \
									  | __LP_GPIO_5 \
									)										// During Low Power mode, keep LPUART
#define ITSDK_LOWPOWER_GPIO_D_KEEP	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank D are all off (not implemented yet)
#define ITSDK_LOWPOWER_GPIO_E_KEEP	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank E are all off (not implemented yet)
#define ITSDK_LOWPOWER_GPIO_H_KEEP	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank H are all off (not implemented yet)
																			// GPIO Wake-Up => the pin should also be in the _KEEP list
#define ITSDK_LOWPOWER_GPIO_A_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank A can be used for wakeup
#define ITSDK_LOWPOWER_GPIO_B_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank B can be used for wakeup
#define ITSDK_LOWPOWER_GPIO_C_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank C can be used for wakeup
#define ITSDK_LOWPOWER_GPIO_D_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank D can be used for wakeup
#define ITSDK_LOWPOWER_GPIO_E_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank E can be used for wakeup
#define ITSDK_LOWPOWER_GPIO_H_WAKE	(__LP_GPIO_NONE)						// During Low Power mode, the GPIO bank H can be used for wakeup

#define ITSDK_SHEDULER_TASKS		1										// Maximum number of Task (0 will deactivate scheduler code)
#define ITSDK_STATEMACHINE_TASKS	0										// Maximum number of state machine task (0 will deactivate STM code)
#define ITSDK_STATEMACHINE_NAMESZ	8										// Maximum size for task name (-1)

#define ITSDK_WITH_SIGFOX_LIB		1										// Include the sigfox code when 1 disabled when 0
#define ITSDK_SIGFOX_LIB			__SIGFOX_S2LP							// Type of Sigfox module


#if ITSDK_PLATFORM == __PLATFORM_STM32L0x1  || ITSDK_PLATFORM == __PLATFORM_STM32L0x3
	#include <stm32l_sdk/config.h>
	#include "stm32l0xx_hal.h"
#endif

#if ITSDK_WITH_SIGFOX_LIB == 1
	#include <it_sdk/configSigfox.h>
#endif

#include <it_sdk/configDrivers.h>

#endif /* IT_SDK_CONFIG_H_ */
