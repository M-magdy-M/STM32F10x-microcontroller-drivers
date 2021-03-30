/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	5 FEB 2021														*/
/* DESCRIPTION  :	EXTERNAL INTERRUPT DRIVER										*/
/************************************************************************************/

#ifndef _STK_interface_H
#define _STK_interface_H


/**********************************Function Prototypes********************************************/
/*
use this function to initialize systick
Disable Systick and interrupt and select clock*/
 void MSTK_voidInit(void);
 
  /*
 this function is used as a delay functon
 */
 void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
 
 /*
   Excute a certain function one time after certain time without delaying the program
 */
 void MSTK_voidIntervalSignal(u32 copy_u32Ticks, void (*Copy_pf)(void));
 
  /*
   Excute a certain function periodically after certain time without delaying the program
 */
   void MSTK_voidIntervalPeriodic(u32 copy_u32Ticks, void (*Copy_pf)(void));
   
    /*
 this function is used to stop systck timer
 */
 void MSTK_voidStopSystck(u32 Copy_u32Ticks);
 
  /*
 this fuction returns number of elpased ticks 
 */
u32 MSTK_u32GetElapsedTicks(void);

 /*
 this fuction returns number of Remaining ticks 
 */
u32 MSTK_u32GetRemainingTicks(void);

#endif
