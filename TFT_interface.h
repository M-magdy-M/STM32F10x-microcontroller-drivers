/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	17 FEB 2021														*/
/* DESCRIPTION  :	TFT DRIVER
/* USER GUIDE	: 1- configure GPIO PINS
				  2- you need to use STK and GPIO and SPI drivers
				  3- STK clk has to be based on 8 Mhz system so 1 clk = 1 u sec
				  so function timing work proberly
/************************************************************************************/



#ifndef _TFT_INTERFACE_H
#define _TFT_INTERFACE_H



void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16 * Copy_Image);

#endif
