/****************************************************************************
 *
 *   Copyright (c) 2013, 2014 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file board_config.h
 *
 * AeroCore internal definitions
 */

#pragma once

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <px4_config.h>
#include <nuttx/compiler.h>
#include <stdint.h>

__BEGIN_DECLS

/* these headers are not C++ safe */
#include <stm32.h>
#include <arch/board/board.h>

#define UDID_START		0x1FFF7A10
 
/****************************************************************************************************
 * Definitions
 ****************************************************************************************************/

/* LEDs */
#define GPIO_LED0	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN9)
#define GPIO_LED1	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN10)

/* Gyro */
#define GPIO_EXTI_GYRO_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTD|GPIO_PIN2)
#define SENSOR_BOARD_ROTATION_DEFAULT	0 /* SENSOR_BOARD_ROTATION_0_DEG */

/* Accel & Mag */
#define GPIO_EXTI_MAG_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTD|GPIO_PIN4)
#define GPIO_EXTI_ACCEL_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTD|GPIO_PIN3)

/* GPS */
#define GPS_DEFAULT_UART_PORT	"/dev/ttyS0"

/* Power muxes */
/* LOW=battery HIGH=USB */
#define GPIO_POWER_MUX_SENSE	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN5)

/* SPI3--Sensors */
#define PX4_SPI_BUS_SENSORS	3
#define GPIO_SPI_CS_ACCEL_MAG	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN2)
#define GPIO_SPI_CS_GYRO	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN3)
#define GPIO_SPI_CS_BARO	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN4)

/* Nominal chip selects for devices on SPI bus #3 */
#define PX4_SPIDEV_ACCEL_MAG	0
#define PX4_SPIDEV_GYRO		1
#define PX4_SPIDEV_BARO		2

/* PWM
 *
 * Eight PWM outputs are configured.
 *
 * Pins:
 *
 * CH1 : PD12 : TIM4_CH1
 * CH2 : PD13 : TIM4_CH2
 * CH3 : PD14 : TIM4_CH3
 * CH4 : PD15 : TIM4_CH4
 * CH5 : PA0  : TIM5_CH1
 * CH6 : PA1  : TIM5_CH2
 * CH7 : PA2  : TIM5_CH3
 * CH8 : PA3  : TIM5_CH4
 */
#define GPIO_TIM4_CH1OUT	GPIO_TIM4_CH1OUT_2
#define GPIO_TIM4_CH2OUT	GPIO_TIM4_CH2OUT_2
#define GPIO_TIM4_CH3OUT	GPIO_TIM4_CH3OUT_2
#define GPIO_TIM4_CH4OUT	GPIO_TIM4_CH4OUT_2
#define GPIO_TIM5_CH1OUT	GPIO_TIM5_CH1OUT_1
#define GPIO_TIM5_CH2OUT	GPIO_TIM5_CH2OUT_1
#define GPIO_TIM5_CH3OUT	GPIO_TIM5_CH3OUT_1
#define GPIO_TIM5_CH4OUT	GPIO_TIM5_CH4OUT_1

/* PWM
 *
 * Eight PWM inputs are configured.
 *
 * Pins:
 *
 * CH8 : PE5  : TIM9_CH1
 * CH7 : PE6  : TIM9_CH2
 * CH6 : PC6  : TIM3_CH1
 * CH5 : PC7  : TIM3_CH2
 * CH4 : PC8  : TIM3_CH3
 * CH3 : PA8  : TIM1_CH1
 * CH2 : PA9  : TIM1_CH2
 * CH1 : PA10 : TIM1_CH3
 */
#define GPIO_TIM9_CH1IN		GPIO_TIM9_CH1IN_2
#define GPIO_TIM9_CH2IN		GPIO_TIM9_CH2IN_2
#define GPIO_TIM3_CH1IN		GPIO_TIM3_CH1IN_3
#define GPIO_TIM3_CH2IN		GPIO_TIM3_CH2IN_3
#define GPIO_TIM3_CH3IN		GPIO_TIM3_CH3IN_2
#define GPIO_TIM1_CH1IN		GPIO_TIM1_CH1IN_1
#define GPIO_TIM1_CH2IN		GPIO_TIM1_CH2IN_1
#define GPIO_TIM1_CH3IN		GPIO_TIM1_CH3IN_1

// spektrum satellite receiver input
#define GPIO_SPEKTRUM_PWR_EN    (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN15)

/* High-resolution timer */
#define HRT_TIMER		8	/* use timer 8 for the HRT */
#define HRT_TIMER_CHANNEL	1	/* use capture/compare channel */

/* Tone Alarm (no onboard speaker)*/
#define TONE_ALARM_TIMER	10	/* timer 10 */
#define TONE_ALARM_CHANNEL	1	/* channel 1 */
#define GPIO_TONE_ALARM_IDLE	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTB|GPIO_PIN8)
#define GPIO_TONE_ALARM		(GPIO_ALT|GPIO_AF3|GPIO_SPEED_2MHz|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN8)


/****************************************************************************************************
 * Public Types
 ****************************************************************************************************/

/****************************************************************************************************
 * Public data
 ****************************************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************************************
 * Public Functions
 ****************************************************************************************************/

/****************************************************************************************************
 * Name: stm32_spiinitialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the PX4FMU board.
 *
 ****************************************************************************************************/

extern void stm32_spiinitialize(void);

extern void stm32_usbinitialize(void);

/****************************************************************************
* Name: nsh_archinitialize
*
* Description:
*   Perform architecture specific initialization for NSH.
*
*   CONFIG_NSH_ARCHINIT=y :
*     Called from the NSH library
*
*   CONFIG_BOARD_INITIALIZE=y, CONFIG_NSH_LIBRARY=y, &&
*   CONFIG_NSH_ARCHINIT=n :
*     Called from board_initialize().
*
****************************************************************************/

#ifdef CONFIG_NSH_LIBRARY
int nsh_archinitialize(void);
#endif

#endif /* __ASSEMBLY__ */

__END_DECLS
