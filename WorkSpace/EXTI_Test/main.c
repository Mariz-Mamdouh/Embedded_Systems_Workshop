
/***************< LIB ******************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/***************< MCAL *****************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

/***************< APP ******************/
void APP_TogLED(void);

int main(void)
{
	/*< Init SYSCLK */
	MCAL_RCC_InitSysClock();
	
	/*< Enable AFIO */
	MCAL_RCC_EnablePeripheral(RCC_APB2ENR_AFIOEN,RCC_APB2);
	
	/*< Enable PORT A */
	MCAL_RCC_EnablePeripheral(RCC_APB2ENR_IOPAEN,RCC_APB2);
	
	/*< Select Pin 0 Mode to Input Pull-Down -> Push Button */
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_INPUT_PULL_DOWN);
	/*< Select Pin 2 Mode to Output Push-Pull -> LED */
	MCAL_GPIO_SetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_PUSH_PULL_2MHZ);

	/*< Enable NVIC Bit for EXTI0 */
	MCAL_NVIC_EnableIRQ(NVIC_EXTI0_IRQn);
	
	/*< Select Port A Pin0 to work as EXTI0 */
	MCAL_EXTI_InitForGPIO(GPIO_PORTA,GPIO_PIN0);
	
	/*< Set EXTI0 to be Rising Edge Sensitive */
	MCAL_EXTI_SetTrigger(EXTI_LINE0,EXTI_RISING_EDGE);
	
	/*< Enable EXTI0 */
	MCAL_EXTI_EnableLine(EXTI_LINE0);
	
	/**< Set callback Fucntion */
	MCAL_EXTI_SetCallBack(EXTI_LINE0, APP_TogLED);
	
	for(;;);
}

 void APP_TogLED(void)
{
	static u8 Temp = 0;
	if(Temp == 0)
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
		Temp = 1;
	}
	else
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
		Temp = 0;
	}
}

