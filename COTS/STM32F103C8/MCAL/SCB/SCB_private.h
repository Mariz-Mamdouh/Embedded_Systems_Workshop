/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 11 Sept 2023    ************/
/*********   Version   : 0.1             ************/
/*********   File name : SCB_private.h   ************/
/****************************************************/
#ifndef SCB_PRIVATE_H
#define SCB_PRIVATE_H


#define SCB_AIRCR           (*((volatile u32 *)(0xE000ED0C))) /**< APPLICATION INTERRUPT AND RESET CONTROL REGISTER */

/**
 * @brief Priority Grouping Values
 * @{
 */
#define SCB_16GROUP_0SUB   0x05FA0300U /**< 16 Priority Levels, No Sub-priority */
#define SCB_8GROUP_2SUB    0x05FA0400U /**< 8 Priority Levels, 2 Sub-priority Levels */
#define SCB_4GROUP_4SUB    0x05FA0500U /**< 4 Priority Levels, 4 Sub-priority Levels */
#define SCB_2GROUP_8SUB    0x05FA0600U /**< 2 Priority Levels, 8 Sub-priority Levels */
#define SCB_0GROUP_16SUB   0x05FA0700U /**< No Grouping, 16 Sub-priority Levels */
/** @} */


#endif /**< SCB_PRIVATE_H */