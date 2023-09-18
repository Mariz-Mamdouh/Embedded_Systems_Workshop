/************************< LIB  **********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/************************< MCAL **********************/
#include "RCC_interface.h"
#include "GPIO_interface.h"


int main(void)
{
	/**< Enable SYSCLK */
	Mcal_Rcc_InitSysClock();
	
	/**< Enable GPIO Peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2ENR_IOPAEN,RCC_APB2);
	
	/**< Set PIN4, PIN5, PIN6 In Port A */
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUT_PUSH_PULL_2MHZ);

	/**< Set PIN4, PIN5, PIN6 In Port B */
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN4,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN5,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN6,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	/**< Set PIN13 In Port C*/
	MCAL_GPIO_SetPinMode(GPIO_PORTC,GPIO_PIN13,GPIO_INPUT_PULL_UP);
	
	
	
	for(;;)
	{
		
	}
}
