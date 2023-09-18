/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 28 Aug 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : RCC_config.h    ************/
/****************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/**
 * @brief Select the system clock source.
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK  RCC_HSE


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE
    #define RCC_CLK_BYPASS   RCC_CRYSTAL_CLK
#endif /*RCC_SYSCLK*/ 

/**
 * @brief Configure the clock Source for PLL.
 * @note Choose one of the available options:
 *       RCC_PLLSRC_HSI      - HSI oscillator clock / 2 selected as PLL input clock.
 *       RCC_PLLSRC_HSE      - HSE oscillator clock selected as PLL input clock.
 */
#if RCC_SYSCLK == RCC_PLL
    #define RCC_PLLSRC  RCC_PLLSRC_HSE

    /**
     * @brief Select if the clock Source will be divided or not when using HSE as a clock source for PLL.
     * @note Choose one of the available options:
     *       RCC_PLL_HSEDV       - HSE clock divided by 2.
     *       RCC_PLL_HSENDV      - HSE clock not divided.
     */
    #if RCC_PLLSRC == RCC_PLLSRC_HSE
        #define RCC_PLLXTPRE   RCC_PLL_HSEDV
    #endif /**< RCC_PLLSRC*/

#endif /**< RCC_SYSCLK */

/**
 * @brief Select PLL multiplication factor.
 * @note Choose one of the available options:
 *      RCC_PLLX2:  PLL input clock x 2
 *      RCC_PLLX3:  PLL input clock x 3
 *      RCC_PLLX4:  PLL input clock x 4
 *      RCC_PLLX5:  PLL input clock x 5
 *      RCC_PLLX6:  PLL input clock x 6
 *      RCC_PLLX7:  PLL input clock x 7
 *      RCC_PLLX8:  PLL input clock x 8
 *      RCC_PLLX9:  PLL input clock x 9
 *      RCC_PLLX10: PLL input clock x 10
 *      RCC_PLLX11: PLL input clock x 11
 *      RCC_PLLX12: PLL input clock x 12
 *      RCC_PLLX13: PLL input clock x 13
 *      RCC_PLLX14: PLL input clock x 14
 *      RCC_PLLX15  PLL input clock x 15
 *      RCC_PLLX16: PLL input clock x 16
 *      RCC_PLLX16: PLL input clock x 16
*/
#if RCC_SYSCLK == RCC_PLL
    #define RCC_PLLMUL RCC_PLLX2
#endif /**< RCC_SYSCLK*/

/** @} */ // end of RCC_System_Clock_Config 


#endif /**< RCC_CONFIG_H */