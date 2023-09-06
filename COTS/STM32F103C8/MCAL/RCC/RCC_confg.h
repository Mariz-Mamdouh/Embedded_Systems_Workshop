/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 28 Aug 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : RCC_confg.h     ************/
/****************************************************/
#ifndef RCC_CONFG_H
#define RCC_CONFG_H

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
#define RCC_SYSCLK  RCC_PLL


/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 * @note Choose one of the available options:
 *       RCC_RC_CLK       - RC oscillator will be the source of the clock system.
 *       RCC_CRYSTAL_CLK - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK==RCC_HSE

#define RCC_CLK_BYPASS   RCC_RC_CLK

#endif /*RCC_SYSCLK*/ 

/**
 * @brief Configure the clock Source wor PLL.
 * @note Choose one of the available options:
 *       RCC_PLLSRC_HSI      - HSI oscillator clock / 2 selected as PLL input clock.
 *       RCC_PLLSRC_HSE      - HSE oscillator clock selected as PLL input clock.
 */
#if RCC_SYSCLK == RCC_PLL

#define RCC_PLLSRC  RCC_PLLSRC_HSE

#endif /**< RCC_SYSCLK */

/** @} */ // end of RCC_System_Clock_Config 



#endif /*RCC_CONFG_H*/
