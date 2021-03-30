/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	5 FEB 2021														*/
/* DESCRIPTION  :	SYSTICK DRIVER										*/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/*Define call back global variable*/
static void (*MSTK_pf_CallBack)(void);
/*Define global variable for systck interrupt exceptions*/
static u8 MSTK_u8ModeOfInterval = 0;

/*
use this function to initialize systick
Disable Systick and interrupt and select clock*/
 void MSTK_voidInit(void)
 {
	 #if	MSTCK_CLK_SRC == MSTK_SRC_AHB_8
		MSTK -> CTRL = 0x00000000;
	 #elif	MSTCK_CLK_SRC == MSTK_SRC_AHB
		MSTK -> CTRL = 0x00000040;	
	 #else
		#error "wrong choice Prescaler for systick"
	 #endif
 }
 /*
 this function is used as a delay functon
 */
 void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
 {
	 /*Load ticks to LOAD reg*/
	 MSTK -> LOAD = Copy_u32Ticks;
	 /*Start count == enable*/
	 SET_BIT(MSTK -> CTRL, 0);
	 /*wait till flag raised "POLLING"*/
	 while(GET_BIT(MSTK -> CTRL, 16) == 0);
	 /* stop timer == disable */
 	 CLR_BIT(MSTK -> CTRL, 0);
	 MSTK -> LOAD  =0 ;
	 MSTK -> VAL  =0 ;
 }
 /*
   Excute a certain function one time after certain time without delaying the program
 */
 void MSTK_voidIntervalSignal(u32 copy_u32Ticks, void (*Copy_pf)(void))
 {
	 /*Load ticks to LOAD reg*/
	 MSTK -> LOAD = Copy_u32Ticks;
	 /*Start count == enable*/
	 SET_BIT(MSTK -> CTRL, 0);	 
	 
	 MSTK_pf_CallBack = Copy_pf;
	 /*Set mode to single*/
	 MSTK_u8ModeOfInterval = MSTK_single_interval;
	 /*Enable systck interrupt*/
	 SET_BIT(MSTK -> CTRL, 1);
 }

  /*
   Excute a certain function periodically after certain time without delaying the program
 */
   void MSTK_voidIntervalPeriodic(u32 copy_u32Ticks, void (*Copy_pf)(void))
   {
	 /*Load ticks to LOAD reg*/
	 MSTK -> LOAD = Copy_u32Ticks;
	 /*Start count == enable*/
	 SET_BIT(MSTK -> CTRL, 0);	 
	 /*Call back*/	 
	 MSTK_pf_CallBack = Copy_pf;
	 /*Set mode to Periodic*/
	 MSTK_u8ModeOfInterval = MSTK_Periodic_interval;
	 /*Enable systck interrupt*/
	 SET_BIT(MSTK -> CTRL, 1);
   }
   
    /*
 this function is used to stop systck timer
 */
 void MSTK_voidStopSystck(u32 Copy_u32Ticks)
 {
	 /*Stop count == enable*/
	 CLR_BIT(MSTK -> CTRL, 0); 
	 /* stop timer == disable */
 	 CLR_BIT(MSTK -> CTRL, 0);
	 MSTK -> LOAD  =0 ;
	 MSTK -> VAL  =0 ;
 }
 /*
 this fuction returns number of elpased ticks 
 */
u32 MSTK_u32GetElapsedTicks(void)
{
	u32 Local_u32Time = 0;
	Local_u32Time = (MSTK -> LOAD  -  MSTK -> VAL);
	
	return Local_u32Time;
}
 /*
 this fuction returns number of Remaining ticks 
 */
u32 MSTK_u32GetRemainingTicks(void)
{
	u32 Local_u32RemainingTicks = 0;
	
	Local_u32Time = (MSTK -> VAL);
	
	return Local_u32RemainingTicks;
}
 /*
 this fuction excute interrupt of systck
 it has no prototype
 function name must be exactly as it is
 in case of single mode it stops the interrupt function from happening again
 */
void SysTick_Handler(void)
{
	u8 Local_u8Temp;
	
	if(MSTK_u8ModeOfInterval = MSTK_single_interval)
	{/*stop systck timer*/
	
	 /*Stop count == enable*/
	 CLR_BIT(MSTK -> CTRL, 0);
	 
	 /* stop timer == disable */
 	 CLR_BIT(MSTK -> CTRL, 0);
	 MSTK -> LOAD  =0 ;
	 MSTK -> VAL  =0 ;
	}
	/**********CallBack function  "Notification"****************/
	MSTK_pf_CallBack();
	
	/**********Clear interrupt flag****************/
	//you can clear the flag by only reading it
	Local_u8Temp = GET_BIT(MSTK -> CTRL, 16);
}