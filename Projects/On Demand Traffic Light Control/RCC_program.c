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
#include "RCC_config.h"

/*****************************< Function Implementations *****************************/
Std_ReturnType MCAL_RCC_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;
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

        Local_FunctionStatus=E_OK;

    #elif RCC_SYSCLK==RCC_HSI

        /**< Enable HSI*/
        SET_BIT(RCC_CR,RCC_CR_HSION);

        /**< wait until the CLK be stable*/
        while(!GET_BIT(RCC_CR,RCC_CR_HSIRDY));

        /**< Select the HSI as a SYSCLK */
        RCC_CFGR=0x00000000;

        Local_FunctionStatus=E_OK;

    #elif RCC_SYSCLK==RCC_PLL

        /**< Select the Clock Source of PLL*/
        #if RCC_PLLSRC==RCC_PLLSRC_HSI
            CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
        #elif RCC_PLLSRC==RCC_PLLSRC_HSE
            SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);

             /**< HSE divider for PLL entry*/
            #if RCC_PLLXTPRE == RCC_PLL_HSEDV
                SET_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
            #elif RCC_PLLXTPRE == RCC_PLL_HSENDV
                CLR_BIT(RCC_CFGR,RCC_CFGR_PLLXTPRE);
            #else
                #error "Wrong choice!" 
            #endif /**< RCC_PLLXTPRE*/
            
        #else
            #error "Wrong choice!" 
        #endif /**< RCC_PLLSRC/

        /**< PLL multiplication factor*/
        switch(RCC_PLLMUL)
        {
            case(RCC_PLLX2):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
           case(RCC_PLLX3):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX4):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX5):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX6):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX7):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX8):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX9):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX10):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX11):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX12):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX13):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX14):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX15):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            case(RCC_PLLX16_1):
                 CLR_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
             case(RCC_PLLX16_2):
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL0);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL1);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL2);
                 SET_BIT(RCC_CFGR,RCC_CFGR_PLLMUL3);
                 break;
            default:
                Local_FunctionStatus=E_NOT_OK;
        }

        /**< Enable PLL*/
        SET_BIT(RCC_CR,RCC_CR_PLLON);

        /**< wait until the CLK be stable*/
        while(!GET_BIT(RCC_CR,RCC_CR_PLLRDY));

        /**< Select the PLL as a SYSCLK */
        CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
        SET_BIT(RCC_CFGR,RCC_CFGR_SW1);

        Local_FunctionStatus=E_OK;

    #else 
        #error "Wrong choice!"

    #endif /**< RCC_SYSCLK*/
    return Local_FunctionStatus;
}
Std_ReturnType MCAL_RCC_EnablePeripheral(u8 Copy_PeripheralId,u8 Copy_BusId)
{
     Std_ReturnType Local_FunctionStatus= E_NOT_OK;
     switch(Copy_BusId)
     {
         /**< Enable the peripheral on the AHB bus. */
        case RCC_AHB:
            SET_BIT(RCC_AHBENR,Copy_PeripheralId);
            Local_FunctionStatus= E_OK;
            break;

        /**< Enable the peripheral on the APB1 bus. */
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR,Copy_PeripheralId);
            Local_FunctionStatus= E_OK;
            break;

        /**< Enable the peripheral on the APB2 bus. */
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR,Copy_PeripheralId);
            Local_FunctionStatus= E_OK;
            break;

        default:
            Local_FunctionStatus= E_NOT_OK;
            break;
     }
    return Local_FunctionStatus;

}
Std_ReturnType MCAL_RCC_DisablePeripheral(u8 Copy_PeripheralId,u8 Copy_BusId)
{
    Std_ReturnType Local_FunctionStatus=E_NOT_OK;
     switch(Copy_BusId)
     {
        /**< Disable the peripheral on the AHB bus. */
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR,Copy_PeripheralId);
            Local_FunctionStatus=E_OK;
            break;

        /**< Disable the peripheral on the APB1 bus. */
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR,Copy_PeripheralId);
            Local_FunctionStatus=E_OK;
            break;

        /**< Disable the peripheral on the APB2 bus. */
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR,Copy_PeripheralId);
            Local_FunctionStatus=E_OK;
            break;

        default:
            Local_FunctionStatus=E_NOT_OK;
            break;
     }

    return Local_FunctionStatus;
}
/*****************************< End of Function Implementations *****************************/
