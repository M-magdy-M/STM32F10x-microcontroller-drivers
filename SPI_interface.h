/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	16 FEB 2021														*/
/* DESCRIPTION  :	SPI DRIVER									  					*/
/************************************************************************************/
#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

void MSPI_voidInit(void);
/*this function send and recieve at same time so if u want to only recieve just send a dummy data
and vice versa*/
void MSPI_voidSendRecieveByte(u8 Copy_u8TransmitData, u8 * Copy_pu8RecieveData);

#endif
