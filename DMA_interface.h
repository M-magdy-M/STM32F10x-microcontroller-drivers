/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	12 FEB 2021														*/
/* DESCRIPTION  :	DMA DRIVER									  					*/
/************************************************************************************/

#ifndef _DMA_INTERFACE_H
#define _DMA_INTERFACE_H

void MDMA_voidInit(void);
void MDMA_voidStartTransfer(u32 * Copy_u32SourceAdr, u32 * Copy_u32DestinationAdr, u16 Copy_u32BlockLenght);

#endif
