/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	8 FEB 2021														*/
/* DESCRIPTION  :	SYSTICK DRIVER										*/
/************************************************************************************/

#ifndef _STK_private_H
#define _STK_private_H

typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	
}MSTK_Type;

#define 	MSTK		((volatile MSTK_Type *)(0xE000E010))
/*
	option :
			1- MSTK_SRC_AHB_8  >>> CLK = AHB/8
			2- MSTK_SRC_AHB	   >>> CLK = AHB/8
*/
#define		MSTK_SRC_AHB_8		2 
#define		MSTK_SRC_AHB		1 

#define 	MSTK_single_interval	0
#define 	MSTK_Periodic_interval	1

#endif