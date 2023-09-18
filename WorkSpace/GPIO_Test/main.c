/*******************< LIB *********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*******************< MCAL ********************/
#include "RCC_interface.h"
#include "GPIO_interface.h"

int main(void)
{
	/**< Init for SYSCLK */
	Mcal_Rcc_InitSysClock();
	
	/**< Enable for Peripheral*/
	Mcal_Rcc_EnablePeripheral(RCC_APB2ENR_IOPAEN,RCC_APB2);
	
	/**< Set PIN0, PIN1, PIN2 In Port A mode */
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT_PUSH_PULL_2MHZ);
	
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_INPUT_PULL_DOWN);
	MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
	
	
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_INPUT_PULL_UP);
  MCAL_GPIO_SetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);
	
	u8 Local_ReturnValue_1;
	
	u8 Local_ReturnValue_2;

	for(;;)
	{
		MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN1,&Local_ReturnValue_1);
		
		MCAL_GPIO_GetPinValue(GPIO_PORTA,GPIO_PIN2,&Local_ReturnValue_2);
	}
}