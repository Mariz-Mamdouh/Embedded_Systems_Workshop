/****************************************************/
/*********   Author    : Mariz Mamdouh     **********/
/*********   Date      : 13 Sept 2023      **********/
/*********   Version   : 0.1               **********/
/*********   File name : AFIO_private.h    **********/
/****************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

/**
 * @defgroup AFIO AFIO (Alternate Function I/O)
 * @brief Header file for the AFIO (Alternate Function I/O) peripheral.
 *
 * This header provides definitions and structures for configuring the AFIO peripheral.
 * It includes the Event Control Register, Multiplexed Pin Assignments Register,
 * External Interrupt Configuration Registers, and Multiplexed Pin Assignments Register 2.
 *
 * @addtogroup Peripheral_Registers Peripheral Registers
 * @{
 */

/**
 * @addtogroup AFIO_Registers AFIO Registers
 * @{
 */

#define AFIO_BASE_ADDRESS 0x40010000

/**
 * @brief AFIO Register Definition Structure
 */
typedef struct
{
    volatile u32 EVCR;         /**< Event Control Register. */
    volatile u32 MAPR;         /**< Multiplexed Pin Assignments Register. */
    volatile u32 EXTICR[4];    /**< External Interrupt Configuration Registers. */
    volatile u32 MAPR2;        /**< Multiplexed Pin Assignments Register 2. */
} AFIO_RegDef_t;

/**< Pointer to AFIO register structure */
#define AFIO  ((AFIO_RegDef_t *)AFIO_BASE_ADDRESS)

/** @} */ // End of AFIO_Registers group

/** @} */ // End of AFIO group

/**
 * @defgroup AFIO_Remap_Definitions AFIO Remap Definitions
 * @{
 */
#define AFIO_MAPR_SWJ_CFG_POS              24
#define AFIO_MAPR_SWJ_CFG_MSK              (0x7 << AFIO_MAPR_SWJ_CFG_POS)

#define AFIO_MAPR_SWJ_CFG_001              (0x1 << AFIO_MAPR_SWJ_CFG_POS)
#define AFIO_MAPR_SWJ_CFG_010              (0x2 << AFIO_MAPR_SWJ_CFG_POS)

#define AFIO_MAPR_ADC2_ETRGREG_REMAP_POS   20
#define AFIO_MAPR_ADC2_ETRGREG_REMAP_MSK   (0x1 << AFIO_MAPR_ADC2_ETRGREG_REMAP_POS)

#define AFIO_MAPR_ADC2_ETRGINJ_REMAP_POS   19
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP_MSK   (0x1 << AFIO_MAPR_ADC2_ETRGINJ_REMAP_POS)

#define AFIO_MAPR_ADC1_ETRGREG_REMAP_POS   18
#define AFIO_MAPR_ADC1_ETRGREG_REMAP_MSK   (0x1 << AFIO_MAPR_ADC1_ETRGREG_REMAP_POS)

#define AFIO_MAPR_ADC1_ETRGINJ_REMAP_POS   17
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP_MSK   (0x1 << AFIO_MAPR_ADC1_ETRGINJ_REMAP_POS)

#define AFIO_MAPR_TIM5CH4_IREMAP_POS       16
#define AFIO_MAPR_TIM5CH4_IREMAP_MSK       (0x1 << AFIO_MAPR_TIM5CH4_IREMAP_POS)

#define AFIO_MAPR_PD01_REMAP_POS           15
#define AFIO_MAPR_PD01_REMAP_MSK           (0x1 << AFIO_MAPR_PD01_REMAP_POS)

#define AFIO_MAPR_CAN_REMAP_POS            13
#define AFIO_MAPR_CAN_REMAP_MSK            (0x3 << AFIO_MAPR_CAN_REMAP_POS)

#define AFIO_MAPR_TIM4_REMAP_POS           12
#define AFIO_MAPR_TIM4_REMAP_MSK           (0x1 << AFIO_MAPR_TIM4_REMAP_POS)

#define AFIO_MAPR_TIM3_REMAP_POS           10
#define AFIO_MAPR_TIM3_REMAP_MSK           (0x3 << AFIO_MAPR_TIM3_REMAP_POS)

#define AFIO_MAPR_TIM2_REMAP_POS           8
#define AFIO_MAPR_TIM2_REMAP_MSK           (0x3 << AFIO_MAPR_TIM2_REMAP_POS)

#define AFIO_MAPR_TIM1_REMAP_POS           6
#define AFIO_MAPR_TIM1_REMAP_MSK           (0x3 << AFIO_MAPR_TIM1_REMAP_POS)

#define AFIO_MAPR_USART3_REMAP_POS         4
#define AFIO_MAPR_USART3_REMAP_MSK         (0x3 << AFIO_MAPR_USART3_REMAP_POS)

#define AFIO_MAPR_USART2_REMAP_POS         3
#define AFIO_MAPR_USART2_REMAP_MSK         (0x1 << AFIO_MAPR_USART2_REMAP_POS)

#define AFIO_MAPR_USART1_REMAP_POS         2
#define AFIO_MAPR_USART1_REMAP_MSK         (0x1 << AFIO_MAPR_USART1_REMAP_POS)

#define AFIO_MAPR_I2C1_REMAP_POS           1
#define AFIO_MAPR_I2C1_REMAP_MSK           (0x1 << AFIO_MAPR_I2C1_REMAP_POS)

#define AFIO_MAPR_SPI1_REMAP_POS           0
#define AFIO_MAPR_SPI1_REMAP_MSK           (0x1 << AFIO_MAPR_SPI1_REMAP_POS)

/** @} */ // End of AFIO_Remap_Definitions

/**
 * @} // End of Peripheral_Registers group
 */ 

#endif /**< AFIO_PRIVATE_H */
