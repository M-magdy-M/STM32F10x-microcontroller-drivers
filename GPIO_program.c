 #include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void	MGPIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode)
{
    //range check
    if((Copy_u8PortID <= GPIO_PORT_C && Copy_u8PortID >= GPIO_PORT_A)&&(Copy_u8PinID<=GPIO_PIN15))
    {
        switch(Copy_u8PortID)
        {
        case GPIO_PORT_A:
            //if pin from 0 to 7 >>>>>>> use CRL reg
            if(Copy_u8PinID <= GPIO_PIN7)
            {
                //first clear pin's 4 bits
                GPIO_A_CRL &= ~ ( (0b1111) << ((u32)Copy_u8PinID * 4));
                //then put mode value in those cleared bits
                GPIO_A_CRL |=   (((u32)Copy_u8Mode) << ((u32)Copy_u8PinID * 4));
            }
            //if pin from 8 to 15 >>>>>>> use CRH reg
            else if(Copy_u8PinID <= GPIO_PIN15)
            {
                //first clear pin's 4 bits
                GPIO_A_CRH &= ~ ( (0b1111) << ( ((u32)Copy_u8PinID - 8) * 4) );
                //then put mode value in those cleared bits
                GPIO_A_CRH |=   ((u32)Copy_u8Mode << ( ((u32)Copy_u8PinID - 8) * 4) );
            }
            else
            {
                //Do nothing
            }
            break;
        /********************************************************************/
        case GPIO_PORT_B:

            //if pin from 0 to 7 >>>>>>> use CRL reg
            if(Copy_u8PinID <= GPIO_PIN7)
            {
                //first clear pin's 4 bits
                GPIO_B_CRL &= ~ ( (0b1111) << ((u32)Copy_u8PinID * 4));
                //then put mode value in those cleared bits
                GPIO_B_CRL |=   ((u32)Copy_u8Mode << ((u32)Copy_u8PinID * 4));
            }
            //if pin from 8 to 15 >>>>>>> use CRH reg
            else if(Copy_u8PinID <= GPIO_PIN15)
            {
                //first clear pin's 4 bits
                GPIO_B_CRH &= ~ ( (0b1111) << ( ((u32)Copy_u8PinID - 8) * 4) );
                //then put mode value in those cleared bits
                GPIO_B_CRH |=   ((u32)Copy_u8Mode << ( ((u32)Copy_u8PinID - 8) * 4) );
            }
            else
            {
                //Do nothing
            }
            break;
        /********************************************************************/
        case GPIO_PORT_C:

            //if pin from 0 to 7 >>>>>>> use CRL reg
            if(Copy_u8PinID <= GPIO_PIN7)
            {
                //first clear pin's 4 bits
                GPIO_C_CRL &= ~ ( (0b1111) << ((u32)Copy_u8PinID * 4));
                //then put mode value in those cleared bits
                GPIO_C_CRL |=   ((u32)Copy_u8Mode << ((u32)Copy_u8PinID * 4));
            }
            //if pin from 8 to 15 >>>>>>> use CRH reg
            else if(Copy_u8PinID <= GPIO_PIN15)
            {
                //first clear pin's 4 bits
                GPIO_C_CRH &= ~ ( (0b1111) << ( ((u32)Copy_u8PinID - 8) * 4) );
                //then put mode value in those cleared bits
                GPIO_C_CRH |=   ((u32)Copy_u8Mode << ( ((u32)Copy_u8PinID - 8) * 4) );
            }
            else
            {
                //Do nothing
            }
            break;
        }
    }
}
void	MGPIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    //range check
    if((Copy_u8PortID <= GPIO_PORT_C && Copy_u8PortID >= GPIO_PORT_A)&&(Copy_u8PinID<=GPIO_PIN15))
    {
        switch(Copy_u8PortID)
        {
        case GPIO_PORT_A:

            if (Copy_u8Value == GPIO_U8_HIGH)
            {
                SET_BIT(GPIO_A_ODR,Copy_u8PinID);
            }
            else
            {
				CLR_BIT(GPIO_A_ODR,Copy_u8PinID);
            }
            break;
        case GPIO_PORT_B:

            if (Copy_u8Value == GPIO_U8_HIGH)
            {
                SET_BIT(GPIO_B_ODR,Copy_u8PinID);
            }
            else
            {
            CLR_BIT(GPIO_B_ODR,Copy_u8PinID);
            }
            break;

        case GPIO_PORT_C:

            if (Copy_u8Value == GPIO_U8_HIGH)
            {
                SET_BIT(GPIO_C_ODR,Copy_u8PinID);
            }
            else
            {
            CLR_BIT(GPIO_C_ODR,Copy_u8PinID);
            }
            break;
        }
    }

}
u8	MGPIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    u8 Local_u8PinVal = 0xFF;
    if((Copy_u8PortID <= GPIO_PORT_C && Copy_u8PortID >= GPIO_PORT_A)&&(Copy_u8PinID<=GPIO_PIN15))
    {
        switch(Copy_u8PortID)
        {
        // 3 cases
        //1 port A +++++++++++++++++++++++++++++++++++++++++++++
        case GPIO_PORT_A:
        	Local_u8PinVal= GET_BIT(GPIO_A_IDR,Copy_u8PinID);
            break;
        //1 port B +++++++++++++++++++++++++++++++++++++++++++++
        case GPIO_PORT_B:
        	Local_u8PinVal= GET_BIT(GPIO_B_IDR,Copy_u8PinID);
            break;
        //1 port A +++++++++++++++++++++++++++++++++++++++++++++
        case GPIO_PORT_C:
        	Local_u8PinVal= GET_BIT(GPIO_C_IDR,Copy_u8PinID);
            break;
        }
    }
    else
    {
        //Do nothing
    }
    return Local_u8PinVal;
}

void	MGPIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Mode)
{
    //range check
    if((Copy_u8PortID <= GPIO_PORT_C && Copy_u8PortID >= GPIO_PORT_A))
    {
        switch(Copy_u8PortID)
        {
        case GPIO_PORT_A:
        {
            u8 i;
            for(i=0; i<=7; i++)
            {
                GPIO_A_CRL &= ~ ((0b1111)<<(i*4));
                GPIO_A_CRL |=   ((Copy_u8Mode)<<(i*4));
            }
            for(i=0; i<=7; i++)
            {
                GPIO_A_CRH &= ~ ((0b1111)<<(i*4));
                GPIO_A_CRH |=   ((Copy_u8Mode)<<(i*4));
            }
            break;
        }
        case GPIO_PORT_B:
        {
            u8 i;
            for(i=0; i<=7; i++)
            {
                GPIO_B_CRL &= ~ ((0b1111)<<(i*4));
                GPIO_B_CRL |=   ((Copy_u8Mode)<<(i*4));
            }
            for(i=0; i<=7; i++)
            {
                GPIO_B_CRH &= ~ ((0b1111)<<(i*4));
                GPIO_B_CRH |=   ((Copy_u8Mode)<<(i*4));
            }
            break;
        }
        case GPIO_PORT_C:
        {
            u8 i;
            /*  for(i=0;i<=7;i++)
              {
                  GPIO_C_CRL &= ~ ((0b1111)<<(i*4));
                  GPIO_C_CRL |=   ((Copy_u8Mode)<<(i*4));
              }*/
            for(i=5; i<=7; i++)
            {
                GPIO_C_CRH &= ~ ((0b1111)<<(i*4));
                GPIO_C_CRH |=   ((Copy_u8Mode)<<(i*4));
            }
            break;
        }
    }
        }
    else
    {
        //Do nothing
    }
}
void	MGPIO_voidSetPortValue(u8 Copy_u8PortID,u16 Copy_u16Value)
{
    //check range
    if((Copy_u8PortID <= GPIO_PORT_B && Copy_u8PortID >= GPIO_PORT_A))
    {
        switch(Copy_u8PortID)
        {
        case GPIO_PORT_A:
            GPIO_A_ODR &= ~ (0xffff);
            GPIO_A_ODR |=  (Copy_u16Value);
            break;
        case GPIO_PORT_B:
            GPIO_B_ODR &= ~ (0xffff);
            GPIO_B_ODR |=  (Copy_u16Value);
            break;
        }

    }
    else
        {
            //Do nothing
        }
}
