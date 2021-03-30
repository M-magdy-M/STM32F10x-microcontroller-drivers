/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	17 FEB 2021														*/
/* DESCRIPTION  :	TFT DRIVER									  					*/
/************************************************************************************/*****************************************************************************/

#ifndef _TFT_PRIVATE_H
#define _TFT_PRIVATE_H

#define HIGH 1
#define LOW  0

void HTFT_voidWriteData(u8 Copy_u8Data);
static void HTFT_voidWriteCommand(u8 Copy_u8Command);

#endif
