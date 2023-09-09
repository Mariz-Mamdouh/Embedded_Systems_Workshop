/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 29 Aug 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : GPIO_confg.h    ************/
/****************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/**
 * @defgroup GPIO_Base_Addresses GPIO Base Addresses
 * @brief Base addresses of GPIO port registers.
 * @{
 */
#define GPIO_PORTA_BASE_ADDRESS     0x40010800U
#define GPIO_PORTB_BASE_ADDRESS     0x40010C00U
#define GPIO_PORTC_BASE_ADDRESS     0x40011000U
/** @} */ // End of GPIO_Base_Addresses group

/**
 * @defgroup GPIO_Registers_Addresses GPIO Registers Addresses
 * @brief Register addresses for GPIO port registers.
 * @{
 */

/******************************************< REGISTERS ADDRESSES FOR PORT A ******************************************/
#define GPIO_PORTA_CRL  (*((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0x00)))
#define GPIO_PORTA_CRH  (*((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0x04)))
#define GPIO_PORTA_IDR  (*((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0x08)))
#define GPIO_PORTA_ODR  (*((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0x0C)))
#define GPIO_PORTA_BSRR (*((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0x10)))
#define GPIO_PORTA_BRR  (*((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0x14)))
#define GPIO_PORTA_LCKR (*((volatile u32*)(GPIO_PORTA_BASE_ADDRESS + 0x18)))

/******************************************< REGISTERS ADDRESSES FOR PORT B ******************************************/
#define GPIO_PORTB_CRL  (*((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0x00)))
#define GPIO_PORTB_CRH  (*((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0x04)))
#define GPIO_PORTB_IDR  (*((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0x08)))
#define GPIO_PORTB_ODR  (*((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0x0C)))
#define GPIO_PORTB_BSRR (*((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0x10)))
#define GPIO_PORTB_BRR  (*((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0x14)))
#define GPIO_PORTB_LCKR (*((volatile u32*)(GPIO_PORTB_BASE_ADDRESS + 0x18)))

/******************************************< REGISTERS ADDRESSES FOR PORT C ******************************************/
#define GPIO_PORTC_CRL  (*((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0x00)))
#define GPIO_PORTC_CRH  (*((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0x04)))
#define GPIO_PORTC_IDR  (*((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0x08)))
#define GPIO_PORTC_ODR  (*((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0x0C)))
#define GPIO_PORTC_BSRR (*((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0x10)))
#define GPIO_PORTC_BRR  (*((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0x14)))
#define GPIO_PORTC_LCKR (*((volatile u32*)(GPIO_PORTC_BASE_ADDRESS + 0x18)))

/** @} */ // End of GPIO_Registers_Addresses group


#endif /**< GPIO_PRIVATE_H*/