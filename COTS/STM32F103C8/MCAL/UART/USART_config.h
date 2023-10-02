/****************************************************/
/*********   Author    : Mariz Mamdouh     **********/
/*********   Date      : 1 Oct 2023        **********/
/*********   Version   : 0.1               **********/
/*********   File name : UART_config.h     **********/
/****************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/**
 * @addtogroup UART_Configuration_Options
 * @{
 */

/**
 * @brief Enumeration for UART parity modes.
 *
 * This enumeration defines the possible parity modes for the UART driver.
 * USART_PARITY_NONE: No parity bit is used.
 * USART_PARITY_EVEN: Even parity is used.
 * USART_PARITY_ODD: Odd parity is used.
 */
typedef enum{
    USART_PARITY_NONE,
    USART_PARITY_EVEN,
    USART_PARITY_ODD
}USART_Parity_t;

/**
 * @brief Enumeration for UART stop bit modes.
 *
 * This enumeration defines the possible stop bit modes for the UART driver.
 * USART_STOP_BITS_1:   1 stop bit is used.
 * USART_STOP_BITS_0_5: 0.5 stop bit is used.
 * USART_STOP_BITS_2:   2 stop bits are used.
 * USART_STOP_BITS_1_5: 1.5 stop bit is used.
 */
typedef enum{
    USART_STOP_BITS_1,
    USART_STOP_BITS_0_5,
    USART_STOP_BITS_2,
    USART_STOP_BITS_1_5
}USART_StopBits_t;

/**
 * @brief Enumeration for UART data word lengths.
 *
 * This enumeration defines the possible data word lengths for the UART driver.
 * USART_DATA_BITS_8: 8 data bits are used.
 * USART_DATA_BITS_9: 9 data bits are used.
 */
typedef enum{
    USART_DATA_BITS_8,
    USART_DATA_BITS_9
}USART_DataBits_t;

/**
 * @brief Enumeration for UART baud rate options.
 *
 * This enumeration defines the possible baud rate options for the UART driver.
 * BAUD_RATE_9600: Baud rate of 9600.
 * BAUD_RATE_115200: Baud rate of 115200.
 * BAUD_RATE_57600: Baud rate of 57600.
 * BAUD_RATE_38400: Baud rate of 38400.
 */
typedef enum{
    BAUD_RATE_9600,
    BAUD_RATE_115200,
    BAUD_RATE_57600,
    BAUD_RATE_38400
}USART_BaudRate_t;



/**
 * @}
 */

#endif /**< USART_CONFIG_H */
