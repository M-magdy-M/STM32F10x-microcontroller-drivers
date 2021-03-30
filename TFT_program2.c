/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	17 FEB 2021														*/
/* DESCRIPTION  :	TFT DRIVER									  					*/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void HTFT_voidInit(void)
{
	/*RESET PULSE SEQUENCE*/
	MGPIO_voidSetPinValue(TFT_RST,LOW);
	MSTK_voidSetBusyWait(1000); //micro
	MGPIO_voidSetPinValue(TFT_RST,HIGH);
	MSTK_voidSetBusyWait(150000); //micro
	/*MGPIO_voidsetPinValue(TFT_RST,HIGH);
	MSTK_voidSetBusyWait(100) //micro
	MGPIO_voidsetPinValue(TFT_RST,LOW);
	MSTK_voidSetBusyWait(100) //micro
	MGPIO_voidsetPinValue(TFT_RST,HIGH);
	MSTK_voidSetBusyWait(120000) //micro*/
	/*Sleep out command*/
	HTFT_voidWriteCommand(0x11);
	MSTK_voidSetBusyWait(150000);//wait 150 ms
	/*color mode command*/
	HTFT_voidWriteCommand(0x3a);
	HTFT_voidWriteData(0x05); // STD COLOR RGB565
	/*Display on command*/
	HTFT_voidWriteCommand(0x29);
}

/*note that this function need u16 variable but use spi function that sends u8 only*/
void HTFT_voidDisplayImage(const u16 * Copy_Image)
{
	u8 Local_u8Data=0;
	
	/*set x curser address at 0*/
	HTFT_voidWriteCommand(0x2A);	
	/*start address (0,0)*/
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	/*end address (0,127)*/
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);

	/*set y curser address at 0*/
	HTFT_voidWriteCommand(0x2B);	
	/*start address (0,0)*/
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);
	/*end address (0,127)*/
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);
	
	/*write ram*/
	//counter must be u16 as every pixel is 2 byte
	for(u16 i= 0; i < 20480 ; i++)
	{
	/*note that this function need u16 variable but use spi function that sends u8 only
	so we send the data on 2 steps, and we need to send the MSB first*/
	
	/*MSB first high byte*/
	Local_u8Data = Copy_Image[i]>>8;
	HTFT_voidWriteData(Local_u8Data); // send
	
	/*then the low byte*/
	Local_u8Data = Copy_Image[i]&0x00ff; //only need first 8 bits
	HTFT_voidWriteData(Local_u8Data); // send
		
	}
}
static void HTFT_voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Dummy= 0;
	/* A0 LOW to send data*/
	MGPIO_voidSetPinValue(TFT_A0,HIGH);//was low
	MSPI_voidSendRecieveByte(Copy_u8Data,&Local_u8Dummy);	
}
static void HTFT_voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Dummy= 0;
	/* A0 HIGH to send command*/
	MGPIO_voidSetPinValue(TFT_A0,LOW);//was HIGH
	MSPI_voidSendRecieveByte(Copy_u8Command,&Local_u8Dummy);	
}


