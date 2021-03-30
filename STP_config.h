/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	12 FEB 2021														*/
/* DESCRIPTION  :	DMA DRIVER												*/
/************************************************************************************/

#ifndef _STP_config_H
#define _STP_config_H

/*choose which port/pin is your data sending pin*/
#define HSTP_DATA_SERIAL	GPIO_PORT_A,GPIO_PIN0

/*choose which port/pin is your storage clk*/
#define HSTP_STORAGE_CLOCK	GPIO_PORT_A,GPIO_PIN1

/*choose which port/pin is your shift clk*/
#define HSTP_SHIFT_CLOCK	GPIO_PORT_A,GPIO_PIN2


#endif
