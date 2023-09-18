/****************************************************/
/*********   Author    : Mariz Mamdouh     **********/
/*********   Date      : 13 Sept 2023      **********/
/*********   Version   : 0.1               **********/
/*********   File name : AFIO_program.c    **********/
/****************************************************/

/************************< LIB ***********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <stdbool.h>
/************************< MCAL **********************/
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

/*****************************< Function Implementations *****************************/

Std_ReturnType AFIO_SetRemap(AFIO_RemapConfig_t Copy_RemapConfig)
{
    /**< Check if the remapConfig is within valid range */ 
    if(Copy_RemapConfig > AFIO_REMAP_CUSTOM)
    {
        return E_NOT_OK;
    }

    /**< Configure the remap settings */
    AFIO->MAPR &= ~(AFIO_MAPR_SWJ_CFG_MSK);

    switch (Copy_RemapConfig)
    {
        case AFIO_REMAP_NONE:
            /**< No remap, SWJ ON without trace (default) */ 
            break;
        case AFIO_REMAP_FULL:
            /**< Full SWJ (JTAG-DP + SW-DP) but without NJTRST */ 
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_001;
            break;
        case AFIO_REMAP_PARTIAL:
            /**< JTAG-DP Disabled and SW-DP Enabled */
            AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_010;
            break;
        case AFIO_REMAP_CUSTOM:
            /**< Custom remap (user-defined) */ 
            break;
        default:
            return E_NOT_OK;
    }
    return E_OK;
}

Std_ReturnType AFIO_SetDebugPort(u8 Copy_DebugConfig)
{
    /**< Check if the DebugConfig value is within a valid range */
    if(Copy_DebugConfig > AFIO_MAPR_SWJ_CFG_MSK)
    {
        return E_NOT_OK;
    }

    /**< Clear the SWJ_CFG bits in the AFIO_MAPR register */ 
    AFIO->MAPR &= ~(AFIO_MAPR_SWJ_CFG_MSK);

    /**< Set the SWJ_CFG bits with the provided DebugConfig value */ 
    AFIO->MAPR |= (Copy_DebugConfig & AFIO_MAPR_SWJ_CFG_MSK);

    return E_OK;
}

Std_ReturnType AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap)
{
    /**< Check if the provided EXTI line or PortMap value is out of range */ 
    if(Copy_Line > 15 || Copy_PortMap > 2)
    {
        return E_NOT_OK;
    }

    /**< Calculate the index of the EXTI control register for the specified line */ 
    u8 Local_RegIndex = Copy_Line / 4;

    /**< Calculate the bit position within the EXTI control register for the specified line */ 
    Copy_Line %= 4;

    /**< Clear the bits that correspond to the EXTI line within the EXTI control register */ 
    AFIO->EXTICR[Local_RegIndex] &= ~((0x0F) << (Copy_Line * 4));

    /**< Set the new PortMap value for the EXTI line within the EXTI control register */ 
    AFIO->EXTICR[Local_RegIndex] |= Copy_PortMap << (Copy_Line * 4);

    return E_OK;
}

/*****************************< End of Function Implementations *****************************/
