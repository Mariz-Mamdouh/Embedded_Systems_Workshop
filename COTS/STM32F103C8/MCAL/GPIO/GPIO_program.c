/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 29 Aug 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : GPIO_confg.h    ************/
/****************************************************/

/************************< LIB ***********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************************< MCAL **********************/
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_confg.h"

/*****************************< Function Implementations *****************************/
Std_ReturnType MCAL_GPIO_SetPinMode(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinMode)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;
    switch (Copy_PortId)
    {
    case GPIO_PORTA:
        if (Copy_PinId < 8)
        {
            GPIO_PORTA_CRL &= ~((0b1111) << (Copy_PinId * 4)); 
            GPIO_PORTA_CRL |= (Copy_PinMode << (Copy_PinId * 4));
            Local_FunctionStatus = E_OK;
        }
        else if (Copy_PinId < 16)
        {
            GPIO_PORTA_CRH &= ~((0b1111) << (Copy_PinId * 4)); 
            GPIO_PORTA_CRH |= (Copy_PinMode << (Copy_PinId * 4));
            Local_FunctionStatus = E_OK;
        }
        else
        {
           Local_FunctionStatus=E_NOT_OK;
        }
        break;
    case GPIO_PORTB:
        if (Copy_PinId < 8)
        {
            GPIO_PORTA_CRL &= ~((0b1111) << (Copy_PinId * 4)); 
            GPIO_PORTA_CRL |= (Copy_PinMode << (Copy_PinId * 4));
            Local_FunctionStatus = E_OK;
        }
        else if (Copy_PinId < 16)
        {
            GPIO_PORTA_CRH &= ~((0b1111) << (Copy_PinId * 4)); 
            GPIO_PORTA_CRH |= (Copy_PinMode << (Copy_PinId * 4));
            Local_FunctionStatus = E_OK;
        }
        else
        {
           Local_FunctionStatus=E_NOT_OK;
        }
        break;
    case GPIO_PORTC:
        if (Copy_PinId < 8)
        {
            GPIO_PORTA_CRL &= ~((0b1111) << (Copy_PinId * 4)); 
            GPIO_PORTA_CRL |= (Copy_PinMode << (Copy_PinId * 4));
            Local_FunctionStatus = E_OK;
        }
        else if (Copy_PinId < 16)
        {
            GPIO_PORTA_CRH &= ~((0b1111) << (Copy_PinId * 4)); 
            GPIO_PORTA_CRH |= (Copy_PinMode << (Copy_PinId * 4));
            Local_FunctionStatus = E_OK;
        }
        else
        {
           Local_FunctionStatus=E_NOT_OK;
        }
        break;
    
    default:
        Local_FunctionStatus=E_NOT_OK;
        break; 
    }

    return Local_FunctionStatus;   
}

Std_ReturnType MCAL_GPIO_SetPinValue(u8 Copy_PortId, u8 Copy_PinId, u8 Copy_PinValue)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;
    switch (Copy_PortId)
    {
    case (GPIO_PORTA):
        switch (Copy_PinValue)
        {
        case (GPIO_HIGH):
            SET_BIT(GPIO_PORTA_ODR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
        case (GPIO_LOW):
            SET_BIT(GPIO_PORTA_ODR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;    
        default:
            Local_FunctionStatus=E_NOT_OK;
            break;
        }
    break;   
    case (GPIO_PORTB):
        switch (Copy_PinValue)
        {
        case (GPIO_HIGH):
            SET_BIT(GPIO_PORTB_ODR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
        case (GPIO_LOW):
            SET_BIT(GPIO_PORTB_ODR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;    
        default:
            Local_FunctionStatus=E_NOT_OK;
            break;
        }
    break;
    case (GPIO_PORTC):
        switch (Copy_PinValue)
        {
        case (GPIO_HIGH):
            SET_BIT(GPIO_PORTC_ODR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
        case (GPIO_LOW):
            SET_BIT(GPIO_PORTC_ODR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;    
        default:
            Local_FunctionStatus=E_NOT_OK;
            break;
        }
    break;
    default:
        Local_FunctionStatus=E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_GPIO_GetPinValue(u8 Copy_PortId, u8 Copy_PinId, u8 *Copy_PinReturnValue)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;
    if(Copy_PinReturnValue != NULL)
    {
        switch (Copy_PortId)
        {
        case GPIO_PORTA:
            *Copy_PinReturnValue = GET_BIT(GPIO_IDR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_PORTB:
            *Copy_PinReturnValue = GET_BIT(GPIO_IDR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;
        case GPIO_PORTC:
            *Copy_PinReturnValue = GET_BIT(GPIO_IDR,Copy_PinId);
            Local_FunctionStatus = E_OK;
            break;    
        default:
            Local_FunctionStatus=E_NOT_OK;
            break;
        }
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;
}
/*****************************< End of Function Implementations *****************************/