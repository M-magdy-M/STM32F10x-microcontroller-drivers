/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	15FEB 2021														*/
/* DESCRIPTION  :	UART DRIVER									  					*/
/************************************************************************************/

#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_type;

#define MUART1 ((volatile UART_type *)(0x40013800))
#define MUART2 ((volatile UART_type *)(0x40004400))
#define MUART3 ((volatile UART_type *)(0x40004800))

#endif
