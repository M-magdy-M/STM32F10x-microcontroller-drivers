/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	15FEB 2021														*/
/* DESCRIPTION  :	UART DRIVER									  					*/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUART1_voidInit(void)
{
	/*Baud rate*/
	/*F CPU = 8Mhz, baudrate = 115200*/
	MUART1-> BRR = 0x45; //115200 for esp wifi
	/******************UART configuration********************/
	
	/*Enable UART + Transmit + Recieve*/
	 SET_BIT(MUART1->CR1,3);//enable transmit
	 SET_BIT(MUART1->CR1,2);//enable recieve
	 SET_BIT(MUART1->CR1,13);//enable UART
	 /*clear status register at initialization*/
	 MUART1->SR = 0;
}

void MUART1_voidTransmit(u8 Copy_u8Data)
{
	MUART1->DR = Copy_u8Data;
	while(GET_BIT(MUART1->SR,6)==0); //POLLING
	
}

u8 MUART1_u8Recieve(void)
{
		while(GET_BIT(MUART1->SR,5)==0); //POLLING

	return MUART1->DR;
}

/*if this function returned 130 then there is time out error*/
u8 MUART1_u8Recieve2(void)
{
	u8 data=0;
	u16 timeout=0;
	while(GET_BIT(MUART1->SR,5)==0) //POLLING
	{
		timeout++;
		if(timeout==30000)
		{
			data=130; //consider 130 as error code
			break;
		}
	}
	if(data==0)
	{
		data = MUART1->DR;
	}
	return data;
}
