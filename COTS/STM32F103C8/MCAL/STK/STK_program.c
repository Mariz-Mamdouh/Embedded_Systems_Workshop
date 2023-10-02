/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 17 Sept 2023    ************/
/*********   Version   : 0.1             ************/
/*********   File name : STK_program.c   ************/
/****************************************************/

/************************< LIB***********************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/************************< MCAL**********************/
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
/*****************************< Function Implementations *****************************/
static STK_CallbackFunc_t STK_Callback = NULL;
static u8 STK_ModeOfInterval;
/*****************************< Function Implementations *****************************/
/**
 * @defgroup Public_Functions STK Driver
 * @{
 */

void MCAL_STK_xInit(u32 Copy_Ticks)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~(STK_CTRL_ENABLE_MASK);

    /**< Configure SysTick timer to use the processor clock */
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
        STK->CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
        STK->CTRL &= ~(STK_CTRL_CLKSOURCE_MASK);          /**< Clear bit 2 to use the processor clock/8 */
    #else
        #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_8."
    #endif /**< STK_CTRL_CLKSOURCE */

    /**< Generate interrupt when it reaches zero */
    #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
        STK->CTRL |= STK_CTRL_TICKINT_MASK;               /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
        STK->CTRL &= ~(STK_CTRL_TICKINT_MASK);            /**< Clear bit 1 to enable interrupt when the counter reaches zero */
    #else 
        #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
    #endif /**< STK_CTRL_TICKINT */

    /**< Load the initial value into the SysTick timer */
    STK->LOAD = Copy_Ticks;

}

void MCAL_STK_vInit(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~(STK_CTRL_ENABLE_MASK);

    /**< Configure SysTick timer to use the processor clock */
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
        STK->CTRL |= STK_CTRL_CLKSOURCE_MASK;             /**< Set bit 2 to use the processor clock */
    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
        STK->CTRL &= ~(STK_CTRL_CLKSOURCE_MASK);          /**< Clear bit 2 to use the processor clock/8 */
    #else
        #error "Invalid STK_CTRL_CLKSOURCE value. Please choose STK_CTRL_CLKSOURCE_1 or STK_CTRL_CLKSOURCE_8."
    #endif /**< STK_CTRL_CLKSOURCE */

    /**< Generate interrupt when it reaches zero */
    #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
        STK->CTRL |= STK_CTRL_TICKINT_MASK;               /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
        STK->CTRL &= ~(STK_CTRL_TICKINT_MASK);            /**< Clear bit 1 to enable interrupt when the counter reaches zero */
    #else 
        #error "Invalid STK_CTRL_TICKINT value. Please choose STK_CTRL_TICKINT_ENABLE or STK_CTRL_TICKINT_DISABLE."
    #endif /**< STK_CTRL_TICKINT */
}

Std_ReturnType MCAL_STK_SetReloadValue(u32 Copy_ReloadValue)
{
    /**< Check if the reload value is within the valid range */ 
    if (Copy_ReloadValue <= STK_RELOAD_MAX)
    {
        /**< Assign the reload value to the STK_LOAD register */ 
        STK->LOAD = Copy_ReloadValue;

        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
    
}

void MCAL_STK_Start(void)
{
    /**< Enable SysTick timer */
    STK->CTRL |= STK_CTRL_ENABLE_MASK;
}

void MCAL_STK_Stop(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~(STK_CTRL_ENABLE_MASK);
}

void MCAL_STK_Reset(void)
{
    /**< Disable SysTick timer */
    STK->CTRL &= ~(STK_CTRL_ENABLE_MASK);

    /**< Clear the current value */
    STK->VAL = 0;

    /**< Set the reload value to 0 */
    STK->LOAD = 0;

    /**< Clear the count flag */
    STK->CTRL &= ~(STK_CTRL_COUNTFLAG_MASK);
}

u32 MCAL_STK_GetRemainingCounts(void)
{
    /* Get the current value of the SysTick timer */
    return STK->VAL;
}

u32 MCAL_STK_GetElapsedCounts(void)
{
    static u32 Local_PreviousValue = 0;    /**< Store the previous SysTick timer value */
    u32 Local_CurrentValue = STK->VAL;     /**< Get the current SysTick timer value */
    u32 Local_ElapsedTicks;

     /**< Check if the timer has wrapped around (current value is less than the previous value) */ 
     if(Local_CurrentValue < Local_PreviousValue)
     {
        /**< Calculate elapsed ticks considering timer overflow */
        Local_ElapsedTicks = Local_PreviousValue - Local_CurrentValue;
     }
     else
     {
        /**< Calculate elapsed ticks without timer overflow */
        Local_ElapsedTicks = STK->LOAD - (Local_CurrentValue - Local_PreviousValue);
     }

    /**< Update the previous value for the next call */ 
    Local_PreviousValue = Local_CurrentValue;

    return Local_ElapsedTicks;
}

Std_ReturnType MCAL_STK_SetBusyWait(u32 Copy_MicroSeconds)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Calculate the number of ticks required for the given microseconds */
    u32 Local_TicksRequired = (Copy_MicroSeconds * (STK_AHB_CLK / 1000000));

    /**< Check if the ticks required is within the valid range */
    if(Local_TicksRequired <= 0x00FFFFFF)
    {
        /**< Set the reload value of the SysTick timer */
        STK->LOAD = Local_TicksRequired;

        /**< Enable SysTick timer */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
        while(!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable SysTick timer */
        STK->CTRL &= ~(STK_CTRL_ENABLE_MASK);

        /**< Reset the timer value */
        STK->VAL = 0;

        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}
Std_ReturnType MCAL_STK_SetDelay_ms(f32 Copy_Milliseconds)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    /**< Calculate the number of ticks required to wait for the specified number of milliseconds */
    u32 Local_u32Ticks = (u32)((Copy_Milliseconds * STK_AHB_CLK) / 1000.0);

    /**< Check if the ticks required is within the valid range */
    if(Local_u32Ticks <= 0x00FFFFFF)
    {
        /**< Set the reload value of the SysTick timer */
        STK->LOAD = Local_u32Ticks;

        /**< Enable SysTick timer */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;

        /**< Wait until the COUNTFLAG bit is set (indicates timer has counted down to zero) */ 
        while(!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK));

        /**< Disable SysTick timer */
        STK->CTRL &= ~(STK_CTRL_ENABLE_MASK);

        /**< Reset the timer value */
        STK->VAL = 0;

        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}

Std_ReturnType MCAL_STK_SetIntervalSingle(u32 Copy_Microseconds, STK_CallbackFunc_t CallbackFunc)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(CallbackFunc != NULL)
    {
        /**< Save the callback function pointer */
        STK_Callback = CallbackFunc;

        /* Calculate the number of ticks required to wait for the specified number of microseconds */
        u32 Local_Ticks = (Copy_Microseconds * STK_AHB_CLK) / 1000000;

        /* Set the reload value for the SysTick timer */
        STK->LOAD = Local_Ticks;

        /**< Set the Mode of interval to be single */
        STK_ModeOfInterval = STK_SINGLE_INTERVAL;

        /* Start the SysTick timer and enable the interrupt */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;
        STK->CTRL |= STK_CTRL_TICKINT_MASK;

        /**< Configured successfully */
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;

}

Std_ReturnType MCAL_STK_SetIntervalPeriodic(u32 Copy_Microseconds, STK_CallbackFunc_t CallbackFunc)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if(CallbackFunc != NULL)
    {
        /**< Save the callback function pointer */
        STK_Callback = CallbackFunc;

        /* Calculate the number of ticks required to wait for the specified number of microseconds */
        u32 Local_Ticks = (Copy_Microseconds * STK_AHB_CLK) / 1000000;

        /* Set the reload value for the SysTick timer */
        STK->LOAD = Local_Ticks-1;

        /**< Set the Mode of interval to be single */
        STK_ModeOfInterval = STK_PERIOD_INTERVAL;

        /* Start the SysTick timer and enable the interrupt */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;
        STK->CTRL |= STK_CTRL_TICKINT_MASK;

        /**< Configured successfully */
        Local_FunctionStatus = E_OK;
    }
    else
    {
        Local_FunctionStatus = E_NOT_OK;
    }

    return Local_FunctionStatus;
}

/**
 * @} // End of Public_Functions
 */

/**
 * @defgroup IRQ_Handlers IRQ Handlers
 * @{
 */

void SysTick_Handler(void)
{
    if(STK_Callback != NULL)
    {
        if(STK_ModeOfInterval == STK_SINGLE_INTERVAL)
        {
            /**< Disable interrupt when the counter reaches zero */
            STK->CTRL &= ~STK_CTRL_TICKINT_MASK;

            /**< Disable SysTick timer */
            STK->CTRL &= STK_CTRL_ENABLE_MASK;

            /**< Clear the current value */
            STK->VAL = 0;

            /**< Set the reload value to 0 */
            STK->LOAD = 0;
        }

        /**< Callback notification */
        STK_Callback();

        /**< Clear the count/interrupt flag */
        STK->CTRL &= STK_CTRL_COUNTFLAG_MASK;
    }
}

/**
 * @} // End of IRQ_Handlers
 */

/*****************************< End of Function Implementations *****************************/
