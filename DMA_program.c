/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	12 FEB 2021														*/
/* DESCRIPTION  :	DMA DRIVER														*/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

/*Define call back global variable*/


/*Define global variable */


/***************************************************************************************************/

void MDMA_voidInit(void)
{
	/*
		Memory to memory
		priority very high
		memory size 32 bit == data bus
		MINC + PINC Activated
		No circualar
		Transfer Interrupt Enable
		channel disable
	*/
	DMA -> Channel[0].CCR = 0x00007AC2;
	
}

void MDMA_voidStartTransfer(u32 * Copy_u32SourceAdr, u32 * Copy_u32DestinationAdr, u16 Copy_u32BlockLenght)
{
	/*make sure DMA channel is disabled */
	CLR_BIT(DMA -> Channel[0].CCR , 0)
	
	/*load destination address*/
	DMA -> Channel[0].CPAR = Copy_u32DestinationAdr;
	
	/*load source address*/
	DMA -> Channel[0].CMAR = Copy_u32SourceAdr;	
	
	/*add block lenght*/
	DMA -> Channel[0].CNDTR = Copy_u32BlockLenght;
	
	/*enable DMA channel at last*/
	SET_BIT(DMA -> Channel[0].CCR , 0)
	
}