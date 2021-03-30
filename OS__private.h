/************************************************************************************/
/* AUTHOR		:	Mohamed Magdy													*/
/* VERSION		:	V1																*/
/* DATE			:	13 FEB 2021														*/
/* DESCRIPTION  :	Serial To Parallel DRIVER														*/
/************************************************************************************/

#ifndef _OS_PRIVATE_H
#define _OS_PRIVATE_H

typedef struct
{
	u16 Periodicity;
	void (* TaskHandler)(void);
	u16 FirstDelay;
	u8 State;
}Task;

#endif
