/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	12 FEB 2021														*/
/* DESCRIPTION  :	DMA DRIVER												*/
/************************************************************************************/

#ifndef 	
#define _DMA_config_H

typedef struct
{
	volatile u32 CCR		;
	volatile u32 CNDTR		;
	volatile u32 CPAR		;
	volatile u32 CMAR		;
	volatile u32 Reserved	;
}DMA_Channel;

typedef struct
{
	volatile u32 ISFR		;
	volatile u32 IFCR		;
	DMA_Channel Channel[7]	;
}DMA_type

#define 	DMA		((volatile DMA_type *)(0x40020000))

#endif
