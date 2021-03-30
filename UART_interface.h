/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	15FEB 2021														*/
/* DESCRIPTION  :	UART DRIVER									  					*/
/************************************************************************************/

#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

void MUART1_voidInit(void);
void MUART1_voidTransmit(u8 Copy_u8Data);
u8 MUART1_u8Recieve(void);

#endif
