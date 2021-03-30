/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	5 FEB 2021														*/
/* DESCRIPTION  :	EXTERNAL INTERRUPT DRIVER										*/
/************************************************************************************/

#ifndef _EXTI_private_H
#define _EXTI_private_H
//new way to declare registers that doesn't waste memory
typedef struct
{
		volatile u32 IMR	;
		volatile u32 EMR	;
		volatile u32 RTSR	;
		volatile u32 FTSR	;
		volatile u32 SWIER	;
		volatile u32 PR		;

}EXTI_type;

#define	EXTI	((volatile EXTI_type *)0x40010400)




#endif