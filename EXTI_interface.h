/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	5 FEB 2021														*/
/* DESCRIPTION  :	EXTERNAL INTERRUPT DRIVER										*/
/************************************************************************************/

#ifndef _EXTI_interface_H
#define _EXTI_interface_H

#define EXTI_FALLING	1
#define EXTI_RISIING	2
#define EXTI_ION		1		//interrupt on change

#defien EXTI_LINE0		0
#defien EXTI_LINE1		1
#defien EXTI_LINE2		2
#defien EXTI_LINE3		3
#defien EXTI_LINE4		4
#defien EXTI_LINE5		5
/* complete to 15 */


void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch(u8 Copy_u8LineID	, u8 Copy_u8LineID);
void MEXTI_voidEnable(u8 Copy_u8LineID);
void MEXTI_voidDisable(u8 Copy_u8LineID);
void MEXTI_voidSetSoftwareTrigger(u8 Copy_u8LineID);
void EXTI0_voidSetCallBack(void (*pf)(void));
void EXTI1_voidSetCallBack(void (*pf)(void));
#endif