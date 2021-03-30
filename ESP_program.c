/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	21 FEB 2021														*/
/* DESCRIPTION  :	ESP DRIVER									  					*/
/************************************************************************************/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "MSTK_interface.h"
#include "SPI_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void HESP_voidInit(void)
{
	//close echo
	//after each command send \r\n for enter and CTRL+J
	MUART1_voidTransmit("ATE0\r\n");
	//make ESP as wifi reciver station
	MUART1_voidTransmit("CWMODE=1\r\n");	
}

void HESP_voidConnectToWifi(void)
{
	MUART1_voidTransmit("AT+CWJAP=\"Zyad_zz\",\"15001500m\"\r\n");
}

void HESP_voidConnectToServer(void)
{
	MUART1_voidTransmit("AT+CIPSTART=\"TCP\",\"IP\",80\r\n");
}

void HESP_voidSend(void)
{
	u8 temp=0;
	MUART1_voidTransmit("AT+CIPSEND=35\r\n");
	MUART1_voidTransmit("GET http://kabansh.ueuo.com/\r\n");
	temp= MUART1_u8Recieve();
}

main()
{
	if(temp[7] == '1')
	{
		MGPIO_voidSetPinValue(,,1);
	}
	esle if (temp[7] == '0')
		{
		MGPIO_voidSetPinValue(,,0);
	}
}


