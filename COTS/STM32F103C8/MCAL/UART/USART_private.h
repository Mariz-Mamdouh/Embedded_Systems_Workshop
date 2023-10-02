/****************************************************/
/*********   Author    : Mariz Mamdouh     **********/
/*********   Date      : 1 Oct 2023        **********/
/*********   Version   : 0.1               **********/
/*********   File name : USART_private.h   **********/
/****************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define USART2_BASE_ADDRESS 0x40004400

typedef struct 
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
}USART_RegDef_t;

#define USART2 ((USART_RegDef_t*)USART2_BASE_ADDRESS)

#define WORD_LENGTH_B  12

/**
 * @brief USART status register (USART_SR) bit definitions.
 */
#define USART_SR_PE       0x00000001  /**< Parity error */
#define USART_SR_FE       0x00000002  /**< Framing error */
#define USART_SR_NE       0x00000004  /**< Noise error flag */
#define USART_SR_ORE      0x00000008  /**< Overrun error */
#define USART_SR_IDLE     0x00000010  /**< IDLE line detected */
#define USART_SR_RXNE     0x00000020  /**< Read data register not empty */
#define USART_SR_TC       0x00000040  /**< Transmission complete */
#define USART_SR_TXE      0x00000080  /**< Transmit data register empty */
#define USART_SR_LBD      0x00000001  /**< LIN break detection flag */
#define USART_SR_CTS      0x00000001  /**< CTS flag */

/**
 * @brief USART control register 1 (USART_CR1) bit definitions.
 */
#define USART_CR1_SBK     0x00000001  /**< Send break */
#define USART_CR1_RWU     0x00000002  /**< Receiver wakeup */
#define USART_CR1_RE      0x00000004  /**< Receiver enable */
#define USART_CR1_TE      0x00000008  /**< Transmitter enable */
#define USART_CR1_IDLEIE  0x00000010  /**< IDLE interrupt enable */
#define USART_CR1_RXNEIE  0x00000020  /**< RXNE interrupt enable */
#define USART_CR1_TCIE    0x00000040  /**< Transmission complete interrupt enable */
#define USART_CR1_TXEIE   0x00000080  /**< TXE interrupt enable */
#define USART_CR1_PEIE    0x00000100  /**< PE interrupt enable */
#define USART_CR1_PS      0x00000200  /**< Parity selection */
#define USART_CR1_PCE     0x00000400  /**< Parity control enable */
#define USART_CR1_WAKE    0x00000800  /**< Wakeup method */
#define USART_CR1_M       0x00001000  /**< Word length */
#define USART_CR1_UE      0x00002000  /**< USART enable */

/**
 * @brief USART control register 2 (USART_CR2) bit definitions.
 */
#define USART_CR2_ADD     0x0000000F  /**< Address of the USART node */
#define USART_CR2_LBDL    0x00000020  /**< LIN break detection length */
#define USART_CR2_LBDIE   0x00000040  /**< LIN break detection interrupt enable */
#define USART_CR2_LBCL    0x00000100  /**< Last bit clock pulse */
#define USART_CR2_CPHA    0x00000200  /**< Clock phase */
#define USART_CR2_CPOL    0x00000400  /**< Clock polarity */
#define USART_CR2_CLKEN   0x00000800  /**< Clock enable */
#define USART_CR2_STOP    0x00003000  /**< STOP bits */
#define USART_CR2_LINEN   0x00004000  /**< LIN mode enable */

/**
 * @brief USART control register 3 (USART_CR3) bit definitions.
 */
#define USART_CR3_EIE     0x00000001  /**< Error interrupt enable 
#define USART_CR3_IREN    0x00000002  /**< IrDA mode enable */
#define USART_CR3_IRPL    0x00000004  /**< IrDA low-power */
#define USART_CR3_HDSEL   0x00000008  /**< Half-duplex selection */
#define USART_CR3_NACK    0x00000010  /**< Smartcard NACK enable */
#define USART_CR3_SCEN    0x00000020  /**< Smartcard mode enable */
#define USART_CR3_DMAR    0x00000040  /**< DMA enable receiver */
#define USART_CR3_DMAT    0x00000080  /**< DMA enable transmitter */
#define USART_CR3_RTSE    0x00000100  /**< RTS enable */
#define USART_CR3_CTSE    0x00000200  /**< CTS enable */
#define USART_CR3_CTSIE   0x00000400  /**< CTS interrupt enable */


#endif /**< USART_PRIVATE_H */
