/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 28 Aug 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : RCC_program.c   ************/
/****************************************************/

/************************< LIB***********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************************< MCAL**********************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_confg.h"


Std_ReturnType Mcal_Rcc_InitSysClock(void)
{
    Std_ReturnType local_FunctionStatus=E_NOT_OK;
    #if RCC_SYSCLK==RCC_HSE
        
        /**< select which External CLK will be entered to the system*/
        #if RCC_CLK_BYPASS==RCC_RC_CLK
            SET_BIT(RCC_CR,RCC_CR_HSEBYP);
        #elif RCC_CLK_BYPASS==RCC_CRYSTAL_CLK
            CLR_BIT(RCC_CR,RCC_CR_HSEBYP);
        #else
            #error "Wrong choice!" 
        #endif /**< RCC_CLK_BYPASS*/

        /**< Enable HSE*/
        SET_BIT(RCC_CR,RCC_CR_HSEON);

        /**< wait until the CLK be stable*/
        while(!GET_BIT(RCC_CR,RCC_CR_HSERDY));

        /**< Select the HSE as a SYSCLK */
        RCC_CFGR=0x00000001;

        local_FunctionStatus=E_OK;

    #elif RCC_SYSCLK==RCC_HSI

        /**< Enable HSI*/
        SET_BIT(RCC_CR,RCC_CR_HSION);

        /**< wait until the CLK be stable*/
        while(!GET_BIT(RCC_CR,RCC_CR_HSIRDY));

        /**< Select the HSI as a SYSCLK */
        RCC_CFGR=0x00000000;

        local_FunctionStatus=E_OK;

    #elif RCC_SYSCLK==RCC_PLL

        /**< Select the Clock Source of PLL*/
        #if RCC_PLLSRC==RCC_PLLSRC_HSI
            CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC)
        #elif RCC_PLLSRC==RCC_PLLSRC_HSE
            SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC)
        #else
            #error "Wrong choice!" 
        #endif /**< RCC_PLLSRC/

        /**< PLL multiplication factor*/
        
        /**< Enable PLL*/
        SET_BIT(RCC_CR,RCC_CR_PLLON);

        /**< wait until the CLK be stable*/
        while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY));

        /**< Select the PLL as a SYSCLK */
        ByteBits_t *ptr=0x40021004;
        ptr -> Bits.Bit0=0;
        ptr -> Bits.Bit0=1;

        local_FunctionStatus=E_OK;

    #else 
        #error "Wrong choice!"

    #endif /**< RCC_SYSCLK*/
    return local_FunctionStatus;
}
Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_PeripheralId,u8 Copy_BusId)
{
     Std_ReturnType local_FunctionStatus= E_NOT_OK;
     switch(Copy_BusId)
     {
         /**< Enable the peripheral on the AHB bus. */
        case RCC_AHB:
            SET_BIT(RCC_AHBENR,Copy_PeripheralId);
            local_FunctionStatus= E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR,Copy_PeripheralId);
            local_FunctionStatus= E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR,Copy_PeripheralId);
            local_FunctionStatus= E_OK;
            break;

        default:
            local_FunctionStatus= E_NOT_OK;
            break;
     }
    return local_FunctionStatus;

}
Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_PeripheralId,u8 Copy_BusId)
{
    Std_ReturnType local_FunctionStatus=E_NOT_OK;
     switch(Copy_BusId)
     {
        /**< Disable the peripheral on the AHB bus. */
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR,Copy_PeripheralId);
            local_FunctionStatus=E_OK;
            break;

        /**< Disable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR,Copy_PeripheralId);
            local_FunctionStatus=E_OK;
            break;

        /**< Disable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR,Copy_PeripheralId);
            local_FunctionStatus=E_OK;
            break;

        default:
            local_FunctionStatus=E_NOT_OK;
            break;
     }

    return local_FunctionStatus;
}
