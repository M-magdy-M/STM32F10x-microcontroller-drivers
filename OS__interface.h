/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	13 FEB 2021														*/
/* DESCRIPTION  :	OS DRIVER									  					*/
/************************************************************************************/

#ifndef _OS_INTERFACE_H
#define _OS_INTERFACE_H
void OS_voidInit(void);
void OS_voidCreateTask(u8 Copy_u8periority,u16 Copy_u16Periodicity,void (* Copy_pf)(void));

void OS_voidSchedular(void);



#endif
