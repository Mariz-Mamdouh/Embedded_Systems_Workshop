/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 19 Sept 2023    ************/
/*********   Version   : 0.1             ************/
/*********   File name : LED.h           ************/
/****************************************************/
#ifndef LED_H
#define LED_H

/**
 * @addtogroup LED_Parameters
 * @{
 */

/**
 * @brief LED Port Enumeration
 *
 * Enumeration of available LED ports.
 */
typedef enum
{
    LED_PORTA,
    LED_PORTB,
    LED_PORTC
}LED_Port_t;

/**
 * @brief LED Pin Enumeration
 *
 * Enumeration of available LED pins.
 */
typedef enum 
{
    LED_PIN0,
    LED_PIN1,
    LED_PIN2,
    LED_PIN3,
    LED_PIN4,
    LED_PIN5,
    LED_PIN6,
    LED_PIN7,
    LED_PIN8,
    LED_PIN9,
    LED_PIN10,
    LED_PIN11,
    LED_PIN12,
    LED_PIN13,
    LED_PIN14,
    LED_PIN15,
}LED_Pin_t;

/**
 * @} (LED_Parameters)
 */

/**
 * @defgroup LED_Functions LED Functions
 * @{
 */

/**
 * @brief Initialize an LED
 *
 * Initializes the specified LED pin for output.
 *
 * @param[in] Copy_LEDPortId The ID of the LED port.
 * @param[in] Copy_LEDPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if initialization is successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_Init(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId);

/**
 * @brief Turn On an LED
 *
 * Turns on the specified LED.
 *
 * @param[in] Copy_LEDPortId The ID of the LED port.
 * @param[in] Copy_LEDPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_On(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId);

/**
 * @brief Turn Off an LED
 *
 * Turns off the specified LED.
 *
 * @param[in] Copy_LEDPortId The ID of the LED port.
 * @param[in] Copy_LEDPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_Off(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId);

/**
 * @brief Toggle an LED
 *
 * Toggles the state of the specified LED.
 *
 * @param[in] Copy_LEDPortId The ID of the LED port.
 * @param[in] Copy_LEDPinId The ID of the LED pin.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_Toggle(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId);

/**
 * @brief Blink an LED Once
 *
 * Blinks the specified LED once with a specified delay.
 *
 * @param[in] Copy_LEDPortId The ID of the LED port.
 * @param[in] Copy_LEDPinId The ID of the LED pin.
 * @param[in] Copy_BlinkTime The delay in milliseconds for each blink.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_BlinkOnce(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId, u32 Copy_BlinkTime);

/**
 * @brief Blink an LED Twice
 *
 * Blinks the specified LED twice with a specified delay between blinks.
 *
 * @param[in] Copy_LEDPortId The ID of the LED port.
 * @param[in] Copy_LEDPinId The ID of the LED pin.
 * @param[in] Copy_BlinkTime The delay in milliseconds for each blink.
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurs.
 */
Std_ReturnType HAL_LED_BlinkTwice(LED_Port_t Copy_LEDPortId, LED_Pin_t Copy_LEDPinId, u32 Copy_BlinkTime);

/**
 * @} (end of LED_Functions)
 */

#endif /**< LED_H */
