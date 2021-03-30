/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	16 FEB 2021														*/
/* DESCRIPTION  :	SPI DRIVER									  					*/
/************************************************************************************/*****************************************************************************/

#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H

typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
}SPI_type;

#define SPI1 	((volatile SPI_type *)(0x40013000))
#define SPI2 	((volatile SPI_type *)(0x40003800))
#define SPI3 	((volatile SPI_type *)(0x40003C00))

#endif
