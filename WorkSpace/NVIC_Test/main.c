#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SCB_interface.h"

int main(void)
{
	Mcal_Rcc_InitSysClock();
	
	Mcal_NVIC_EnableIRQ(NVIC_SPI1_IRQn);
	
	Mcal_NVIC_xSetPriority(NVIC_SPI1_IRQn,10);
	
	Mcal_NVIC_SetPendingIRQ(NVIC_SPI1_IRQn);
	
	Mcal_NVIC_ClearPendingIRQ(NVIC_SPI1_IRQn);
	
	Mcal_NVIC_DisableIRQ(NVIC_SPI1_IRQn);
	
	Mcal_NVIC_EnableIRQ(NVIC_SPI2_IRQn);
	
	Mcal_NVIC_xSetPriority(NVIC_SPI2_IRQn,8);
	
	
	for(;;)
	{
		
	}

}
