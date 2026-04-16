/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU      STM32F411

#define BOARD_NAME         MERLYN411
#define MANUFACTURER_ID    ANSON

// ---- INTERNAL COMPONENTS ----
#define USE_ACC
#define USE_ACC_MPU6500
#define USE_ACC_SPI_MPU6500

#define USE_GYRO
#define USE_GYRO_MPU6500
#define USE_GYRO_SPI_MPU6500

#define USE_MAX7456

#define USE_FLASH
#define USE_FLASH_W25Q128FV

// ---- EXTERNAL CONNECTABLE COMPONENTS ---
#define USE_MAG
#define USE_MAG_AK8963
#define USE_MAG_AK8975
#define USE_MAG_HMC5883
#define USE_MAG_IST8310
#define USE_MAG_LIS2MDL
#define USE_MAG_LIS3MDL
#define USE_MAG_QMC5883
#define USE_MPU9250_MAG
#define USE_MAG_MPU925X_AK8963

#define USE_GPS
#define USE_RANGEFINDER
#define USE_ALTITUDE_HOLD
#define USE_POSITION_HOLD

#define USE_TELEMETRY
#define USE_TELEMETRY_LTM
#define USE_TELEMETRY_CRSF
#define USE_TELEMETRY_GHST
#define USE_TELEMETRY_HOTT
#define USE_TELEMETRY_IBUS
#define USE_TELEMETRY_SRXL
#define USE_TELEMETRY_MAVLINK
#define USE_TELEMETRY_SMARTPORT
#define USE_TELEMETRY_FRSKY_HUB
#define USE_TELEMETRY_IBUS_EXTENDED

// ---- PIN MAPPING ----
#define LED0_PIN             PA8

#define ADC_VBAT_PIN         PB0
#define ADC_CURR_PIN         PB1
#define BEEPER_PIN           PB2

#define MOTOR1_PIN           PB4
#define MOTOR2_PIN           PB5
#define MOTOR3_PIN           PB6
#define MOTOR4_PIN           PB7

#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3

#define USE_SOFTSERIAL
#define USE_SOFTSERIAL1
#define SOFTSERIAL1_TX_PIN   PA15

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

#define GYRO_1_CS_PIN        PA4
#define FLASH_CS_PIN         PB10
#define MAX7456_SPI_CS_PIN   PB12

// ---- TIMER MAPPING ----
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 1, PB4 , 1,  0) \
    TIMER_PIN_MAP( 2, PB5 , 1,  0) \
    TIMER_PIN_MAP( 3, PB6 , 1,  0) \
    TIMER_PIN_MAP( 4, PB7 , 1,  0) \
    TIMER_PIN_MAP( 5, PA15, 1,  0)

// ---- HARDWARE INSTANCES ----
#define ADC1_DMA_OPT         1
#define MAG_I2C_INSTANCE     (I2CDEV_1)
#define BARO_I2C_INSTANCE    (I2CDEV_1)
#define GYRO_1_SPI_INSTANCE  SPI1
#define FLASH_SPI_INSTANCE   SPI2
#define MAX7456_SPI_INSTANCE SPI2
#define SYSTEM_HSE_MHZ       25