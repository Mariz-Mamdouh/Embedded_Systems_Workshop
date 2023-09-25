/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 22 Sep 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : main.c          ************/
/****************************************************/
/*********************< LIB  ************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*********************< MCAL ************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
/*********************< HAL  ************************/
#include "LED.h"

/*********************< APP  ************************/
int main(void)
{
		/*********************< Init  ************************/

		/**< Enable SYSCLK */
		MCAL_RCC_InitSysClock();
		
		/**< Enable Peripheral */
		MCAL_RCC_EnablePeripheral(RCC_APB2ENR_IOPAEN,RCC_APB2);
		MCAL_RCC_EnablePeripheral(RCC_APB2ENR_IOPBEN,RCC_APB2);
		
		/**< Set PIN5, PIN6, PIN7 In Port A */
			/**< PIN5,PIN6,PIN7 for Cars Traffic Light */
		HAL_LED_Init(GPIO_PORTA,GPIO_PIN5); //Green
		HAL_LED_Init(GPIO_PORTA,GPIO_PIN6); //Yellow
		HAL_LED_Init(GPIO_PORTA,GPIO_PIN7); //Red

		/**< Set PIN1, PIN5, PIN6, PIN7 In Port B */
			/**< PIN1 For Button */
		MCAL_GPIO_SetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_INPUT_PULL_UP);
			/**< PIN5,PIN6,PIN7 for Pedestrians Traffic Light */
		HAL_LED_Init(GPIO_PORTB,GPIO_PIN5); //Green
		HAL_LED_Init(GPIO_PORTB,GPIO_PIN6); //Yellow
		HAL_LED_Init(GPIO_PORTB,GPIO_PIN7); //Red
		
		
		for(;;)
		{
			/*********************< Body  ************************/
			
			/**< Turn ON the Cars green light and the Pedestrians red light for 5 sec then Turn OFF both */										
			HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN5);
			HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN7);
			
			/*< Check the Button while the cars green light is ON and the Pedestrians red light is ON*/
			for(u8 x=0;x<100;x++)
			{
				/**< Check if the Press on the button is long or short */
				u8 PreviousValue = GET_BIT((*((volatile u32 *)(0x40010C08U))),GPIO_PIN1);
				if(PreviousValue == 1)
				{
					MCAL_STK_SetDelay_ms(500);
					u8 CurrentValue = GET_BIT((*((volatile u32 *)(0x40010C08U))),GPIO_PIN1);

					/**< Long Press */
					if(CurrentValue == 1)
					{
						MCAL_STK_SetDelay_ms(500);
					}
					
					/*< Short Press*/
					else if(CurrentValue == 0)
					{
						HAL_LED_Off(GPIO_PORTA,GPIO_PIN5);
						HAL_LED_Off(GPIO_PORTB,GPIO_PIN7);
						
						/**< Blinking yellow Lights for 5 sec then Turn OFF */
						for(u8 i=0;i<10;i++)
						{
							HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN6);
							HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN6);
							MCAL_STK_SetDelay_ms(500);
						}
						HAL_LED_Off(GPIO_PORTA,GPIO_PIN6);
						HAL_LED_Off(GPIO_PORTB,GPIO_PIN6);
						
						/**< Turn ON the Cars red light and the Pedestrians green light for 5 sec then Turn OFF both */					
						HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN7);
						HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN5);
						MCAL_STK_SetDelay_ms(5000);
						HAL_LED_Off(GPIO_PORTA,GPIO_PIN7);
						HAL_LED_Off(GPIO_PORTB,GPIO_PIN5);

						/**< Blinking yellow Lights for 5 sec then Turn OFF */					
						for(u8 j=0;j<10;j++)
						{
							HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN6);
							HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN6);
							MCAL_STK_SetDelay_ms(500);
						}
						HAL_LED_Off(GPIO_PORTA,GPIO_PIN6);
						HAL_LED_Off(GPIO_PORTB,GPIO_PIN6);
						
						/**< Turn ON the Cars green light and the Pedestrians red light for 5 sec then Turn OFF both */										
						HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN5);
						HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN7);
						MCAL_STK_SetDelay_ms(5000);
					}
				}
				MCAL_STK_SetDelay_ms(x);
			}
			
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN5);
			HAL_LED_Off(GPIO_PORTB,GPIO_PIN7);
					
			/**< Blinking yellow Lights for 5 sec then Turn OFF */
			for(u8 i=0;i<10;i++)
			{
				HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN6);
				HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN6);
				MCAL_STK_SetDelay_ms(500);
			}
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN6);
			HAL_LED_Off(GPIO_PORTB,GPIO_PIN6);
			
			/**< Turn ON the Cars red light and the Pedestrians green light for 5 sec then Turn OFF both */
			HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN7);
			HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN5);
			MCAL_STK_SetDelay_ms(5000);
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN7);
			HAL_LED_Off(GPIO_PORTB,GPIO_PIN5);
			
			/**< Blinking yellow Lights for 5 sec then Turn OFF */
			for(u8 j=0;j<10;j++)
			{
				HAL_LED_Toggle(GPIO_PORTA,GPIO_PIN6);
				HAL_LED_Toggle(GPIO_PORTB,GPIO_PIN6);
				MCAL_STK_SetDelay_ms(500);
			}
			HAL_LED_Off(GPIO_PORTA,GPIO_PIN6);
			HAL_LED_Off(GPIO_PORTB,GPIO_PIN6);
			
		}
}

