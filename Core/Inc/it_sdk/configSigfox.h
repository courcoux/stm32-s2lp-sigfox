/* ==========================================================
 * configSigfox.h - SDK Configuration file for Sigfox communication
 * Project : IngeniousThings SDK
 * ----------------------------------------------------------
 * Created on: 4 nov. 2018
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

#ifndef IT_SDK_CONFIG_SIGFOX_H_
#define IT_SDK_CONFIG_SIGFOX_H_

#include <it_sdk/config_defines.h>
#if ITSDK_SIGFOX_LIB == __SIGFOX_S2LP
	#include "spi.h"
#endif

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// | SDK SETTING                   | USER SELECTED VALUE                  | SETTING DESCRIPTION                   |
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +---------COMMON SETTINGS-------|--------------------------------------|---------------------------------------|


// +---------------S2LP------------|--------------------------------------|---------------------------------------|
#if ITSDK_SIGFOX_LIB == __SIGFOX_S2LP
#define ITSDK_S2LP_SPI				hspi1								   // SPI To BE USED
																		   // SPI Configured by CubeMX
																		   //  Master, 8b, Polarity Low,
																		   //  first bit msb, CRC disable...

#define ITSDK_S2LP_CS_BANK			 __BANK_A							   // S2LP Chip Select PIN LAYOUT (Activ Low)
#define ITSDK_S2LP_CS_PIN			 __LP_GPIO_8
#define ITSDK_S2LP_INT_BANK			 __BANK_C							   // S2LP Interrupt PIN LAYOUT
#define ITSDK_S2LP_INT_PIN			 __LP_GPIO_0						   //   Default PC0 <=> GPIO3 on S2LP
																		   //   Configured as Falling
#endif //__SIGFOX_S2LP
// +-------------OTHERS------------|--------------------------------------|---------------------------------------|




#endif /* IT_SDK_CONFIG_SIGFOX_H_ */

