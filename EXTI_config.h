/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	5 FEB 2021														*/
/* DESCRIPTION  :	EXTERNAL INTERRUPT DRIVER										*/
/************************************************************************************/

#ifndef _EXTI_config_H
#define _EXTI_config_H
/*
		options
					1-	EXTI_FALLING
					2-	EXTI_RISIING
					3-	EXTI_ION		>>interrupt on change
*/
#define EXTI_SENSE_MODE		EXTI_FALLING
/*
		options
					1-	EXTI_LINE0
					2-	EXTI_LINE1
					3-	EXTI_LINE2		>>interrupt on change
*/
#define EXTI_LINE	EXTI_LINE0
#endif
