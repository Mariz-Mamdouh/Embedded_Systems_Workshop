/****************************************************/
/*********   Author    : Mariz Mamdouh     **********/
/*********   Date      : 9 SEPT 2023       **********/
/*********   Version   : 0.1               **********/
/*********   File name : EXTI_interface.h  **********/
/****************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

Std_ReturnType EXTI_Init(void);

Std_ReturnType EXTI_Enable(u8 Copy_Line);

Std_ReturnType EXTI_Disable(u8 Copy_Line);

Std_ReturnType EXTI_SetPinTrigger(u8 Copy_Line , u8 Copy_Mode );

#endif /**< EXTI_INTERFACE_H */