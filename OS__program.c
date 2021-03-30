#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#ifndef NULL
#define NULL (void *)0
#endif

static Tasks Systasks[NO_OF_TASKS];
volatile u16 OS_Ticks = 0;

void OS_voidInit(void)
{
	MSTK_voidIntervalPeriodic(1000, OS_voidSchedular);
}

void OS_voidCreateTask(u8 Copy_u8periority,u16 Copy_u16Periodicity,void (* Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		//priority is set as place in array
		Systasks[Copy_u8periority].Periodicity = Copy_u16Periodicity;
		Systasks[Copy_u8periority].TaskHandler = Copy_pf;
	}
}

void OS_voidSchedular(void)
{
	for(u8 i = 0; i < NO_OF_TASKS; i++)
	{
		if(OS_Ticks % Systasks[i].Periodicity == 0)
		{
			Systasks[i].TaskHandler();
		}
	}
	OS_Ticks++;
}