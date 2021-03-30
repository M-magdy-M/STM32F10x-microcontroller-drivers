#include "STD_TYPES.h"
#include "BIT_MATH.h"

#iclude "GPIO_interface.h"
#iclude "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchrounous(u8 Copy_u8DataToSend)
{
	s8 LOC_u8Counter;
	u8 LOC_u8Bit	;
	
	for(LOC_u8Counter = 7;LOC_u8Counter >= 0 ;LOC_u8Counter--)
	{
		LOC_u8Bit = GET_BIT(Copy_u8DataToSend,LOC_u8Counter); //MSB is sent first
		MGPIO_voidSetPinValue(HSTP_DATA_SERIAL,LOC_u8Bit);//DS---> data serial
		
		/*Send rising edge to shift reg*/
	
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,MGPIO_u8_LOW);//make sure clk is low
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,MGPIO_u8_HIGH);//rising edge 
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,MGPIO_u8_LOW);//then back to
	}
			/*Send rising edge to Storage reg*/

		MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK,MGPIO_u8_LOW);//make sure clk is low
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK,MGPIO_u8_HIGH);//rising edge 
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_STORAGE_CLOCK,MGPIO_u8_LOW);//then back to
}