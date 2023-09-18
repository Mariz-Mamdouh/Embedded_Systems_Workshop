/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 28 Aug 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : RCC_private.h   ************/
/****************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */
#define RCC_CR            (*(volatile u32 *)0x40021000)

/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */
#define RCC_CFGR          (*(volatile u32 *)0x40021004)

/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */
#define RCC_CIR           (*(volatile u32 *)0x40021008)

/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */
#define RCC_APB2RSTR      (*(volatile u32 *)0x4002100C)

/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */
#define RCC_APB1RSTR      (*(volatile u32 *)0x40021010)

/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */
#define RCC_AHBENR        (*(volatile u32 *)0x40021014)

/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */
#define RCC_APB1ENR       (*(volatile u32 *)0x4002101C)

/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */
#define RCC_APB2ENR       (*(volatile u32 *)0x40021018)

/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */
#define RCC_BDCR          (*(volatile u32 *)0x40021020)

/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */
#define RCC_CSR           (*(volatile u32 *)0x40021024)

/** @} */ // end of RCC Control Register (CR)


/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */
#define RCC_CR_HSION      0
#define RCC_CR_HSIRDY     1
#define RCC_CR_HSITRIM    3
#define RCC_CR_HSECAL     8
#define RCC_CR_HSEON      16
#define RCC_CR_HSERDY     17
#define RCC_CR_HSEBYP     18
#define RCC_CR_CSSON      19
#define RCC_CR_PLLON      24
#define RCC_CR_PLLRDY     25

/** @} */ // end of RCC_CR_Bit_Definitions


/**
 * @defgroup RCC_CFGR_Bit_Definitions RCC Configuration Register (RCC_CFGR) Bit Definitions
 * @{
 */
#define RCC_CFGR_SW0      0
#define RCC_CFGR_SW1      1
#define RCC_CFGR_SWS      2
#define RCC_CFGR_HPRE     4
#define RCC_CFGR_PPRE1    8
#define RCC_CFGR_PPRE2    11
#define RCC_CFGR_ADCPRE   14
#define RCC_CFGR_PLLSRC   16
#define RCC_CFGR_PLLXTPRE 17
#define RCC_CFGR_PLLMUL0  18
#define RCC_CFGR_PLLMUL1  19
#define RCC_CFGR_PLLMUL2  20
#define RCC_CFGR_PLLMUL3  21
#define RCC_CFGR_USBPRE   22
#define RCC_CFGR_MCO      24

/** @} */ // end of RCC_CFGR_Bit_Definitions


/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */
#define RCC_HSI           0
#define RCC_HSE           1
#define RCC_PLL           2

/** @} */ // end of RCC_Clock_Source


/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */
#define RCC_CRYSTAL_CLK   0
#define RCC_RC_CLK        1

/** @} */ // end of RCC_Clock_Type

/**
 * @defgroup RCC_PLLMUL RCC PLL multiplication factor Macros
 * @{
 */
    #define RCC_PLLX2    2
    #define RCC_PLLX3    3
    #define RCC_PLLX4    4
    #define RCC_PLLX5    5
    #define RCC_PLLX6    6
    #define RCC_PLLX7    7
    #define RCC_PLLX8    8
    #define RCC_PLLX9    9
    #define RCC_PLLX10   10
    #define RCC_PLLX11   11
    #define RCC_PLLX12   12
    #define RCC_PLLX13   13
    #define RCC_PLLX14   14
    #define RCC_PLLX15   15
    #define RCC_PLLX16_1 16
    #define RCC_PLLX16_2 17

/** @} */ // end of RCC_PLLMUL

#endif /**< RCC_PRIVATE_H */