/************************< LIB  **********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/************************< MCAL **********************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SCB_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "STK_interface.h"


int main(void)
{
	/**< Enable SYSCLK */
	Mcal_Rcc_InitSysClock();
	
	/**< Enable GPIO Peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2ENR_IOPAEN,RCC_APB2);
	
	/**< Set PIN3, PIN5, PIN6, PIN7 In Port A */
		/**< PIN3 For Button */
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_INPUT_PULL_UP);
		/**< PIN5,PIN6,PIN7 for Car Traffic Light*/
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_OUTPUT_PUSH_PULL_2MHZ);

	/**< Set PIN5, PIN6, PIN7 In Port B */
		/**< PIN5,PIN6,PIN7 for People Traffic Light*/
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN5,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN6,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN7,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	/**< Enable interrupt for PIN3 in Port A*/
	EXTI_InitForGPIO(GPIO_PIN3,GPIO_PORTA);
	EXTI_EnableLine(EXTI_LINE3);
	EXTI_SetTrigger(EXTI_LINE3,EXTI_BOTH_EDGES);
	
	for(;;)
	{
		
	}
}
