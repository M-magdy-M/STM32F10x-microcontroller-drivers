/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	16 FEB 2021														*/
/* DESCRIPTION  :	SPI DRIVER									  					*/
/************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_voidInit(void)
{
	SPI1->CR1 = 0x00000347;
}

void MSPI_voidSendRecieveByte(u8 Copy_u8TransmitData, u8 * Copy_pu8RecieveData)
{
	/* slave select = low*/
	MGPIO_voidSetPinValue(SLAVE_SELECT,0);
	/*Send data*/
	SPI1-> DR = Copy_u8TransmitData;
	/*wait on busy flag*/
	while(GET_BIT(SPI1-> SR,7)==1);
	/*Return recieved data*/
	* Copy_pu8RecieveData = SPI1-> DR;
	/*slave select = high*/
	MGPIO_voidSetPinValue(SLAVE_SELECT,1);
}
	