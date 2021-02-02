/************************************************************************************/
/* AUTHOR	:	Mohamed Magdy														*/
/* VERSION	:	V02																	*/
/* DATE		:	2 FEB 2021															*/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitiate(void)
{
    //choose system clock source
    switch(CLOCK_SOURCE)
    {
    case HSI:
        SET_BIT(RCC_CR,0);
        //system clk switch   HSI > 00
        CLR_BIT(RCC_CFGR,0);
        CLR_BIT(RCC_CFGR,1);
        break;
    case HSE:
        SET_BIT(RCC_CR,16);
        //system clk switch   HSE > 01
        SET_BIT(RCC_CFGR,0);
        CLR_BIT(RCC_CFGR,1);
        break;
    case PLL:
    {
        //first: choose PLL source
        switch(PLL_SOURCE)
        {
        case HSE:
            SET_BIT(RCC_CFGR,16);
            CLR_BIT(RCC_CFGR,17);
            break;
        case HALF_HSE:
            SET_BIT(RCC_CFGR,16);
            SET_BIT(RCC_CFGR,17);
            break;
        case HALF_HSI:
            CLR_BIT(RCC_CFGR,16);
            break;
        }
        //second:enable PLL itself
        SET_BIT(RCC_CR,24);
        //third: configure PLL MUL factor
        RCC_CFGR |= (PLL_MUL<<18);
        //system clk switch   PLL > 10
        CLR_BIT(RCC_CFGR,0);
        SET_BIT(RCC_CFGR,1);
    }
    break;//make sure you don't have to enable
        //HSE or HSI with PLL
    }

    //type of external clock
    switch(EXTERNAL_CLk_TYPE)
    {
    case RC     :
        SET_BIT(RCC_CR,18);
        break;
    case CRYSTAL:
        CLR_BIT(RCC_CR,18);
        break;
    }

    //enable security system
    if(RCC_SECURITY_SYSTEM)
    {
        SET_BIT(RCC_CR,19);
    }
    else
    {
        CLR_BIT(RCC_CR,19);
    }
    //choose prescaler
    RCC_CFGR |= (AHB_PRESCALER<<4);
    RCC_CFGR |= (APB1_PRESCALER<<8);
    RCC_CFGR |= (APB2_PRESCALER<<11);
}
void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PerphiralID)
{
    if (Copy_u8PerphiralID < 32)
    {
        switch(Copy_u8BusID)
        {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR,Copy_u8PerphiralID) break;
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR,Copy_u8PerphiralID)break;
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR,Copy_u8PerphiralID) break;

        }
    }
    else
    {
        //do nothing
    }
}
void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PerphiralID)
{
    if (Copy_u8PerphiralID < 32)
    {
        switch(Copy_u8BusID)
        {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR,Copy_u8PerphiralID) break;
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR,Copy_u8PerphiralID)break;
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR,Copy_u8PerphiralID) break;

        }
    }
    else
    {
        //do nothing
    }
}
u8	 RCC_u8ClkCalibration(u8 Copy_u8TrimValue)
{
    u8 caliprated_value;
    u32 aux_caliprated_value;
    if(Copy_u8TrimValue>=0 && Copy_u8TrimValue<32)
    {
    RCC_CR |= (Copy_u8TrimValue<<3);
    }
    aux_caliprated_value = ( (RCC_CR & (0xff<<8) ) >> 8 );
    caliprated_value = (u8)aux_caliprated_value;
    return(caliprated_value);
}

#endif
