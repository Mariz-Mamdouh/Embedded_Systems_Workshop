/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 19 Sept 2023    ************/
/*********   Version   : 0.1             ************/
/*********   File name : LED.c           ************/
/****************************************************/

/*******************< LIB ***************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*******************< MCAL **************************/
#include "GPIO_interface.h"
#include "STK_interface.h"
/*******************< HAL ***************************/
#include "LED.h"

/**
 * @defgroup Public_Functions LED Driver
 * @{
 */
Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId)
{
    /**< Init LED to be output */  
    return MCAL_GPIO_SetPinMode(Copy_LEDPortId, Copy_LEDPinId, GPIO_OUTPUT_PUSH_PULL_2MHZ);
}

Std_ReturnType HAL_LED_On(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LEDPortId, Copy_LEDPinId, GPIO_HIGH);
}

Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId)
{
    return MCAL_GPIO_SetPinValue(Copy_LEDPortId, Copy_LEDPinId, GPIO_LOW);
}

Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId)
{
    return MCAL_GPIO_TogglePin(Copy_LEDPortId, Copy_LEDPinId);
}

Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId, u32 Copy_BlinkTime)
{
    if (MCAL_GPIO_SetPinValue(Copy_LEDPortId, Copy_LEDPinId, GPIO_HIGH) == E_NOT_OK)
    {
        return E_NOT_OK;
    }
    if (MCAL_STK_SetDelay_ms(Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }
    if (MCAL_GPIO_SetPinValue(Copy_LEDPortId, Copy_LEDPinId, GPIO_LOW) == E_NOT_OK)
    {
        return E_NOT_OK;
    }
    return E_OK;
}   

Std_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId, u32 Copy_BlinkTime)
{
    if (HAL_LED_BlinkOnce(Copy_LEDPortId, Copy_LEDPinId, Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    MCAL_STK_SetDelay_ms(Copy_BlinkTime);

    HAL_LED_BlinkOnce(Copy_LEDPortId, Copy_LEDPinId, Copy_BlinkTime);

    return E_OK;
}

/**
 * @} // End of Public_Functions
 */
