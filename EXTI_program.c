#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* momken n3mel array to pointer to functions*/
void (* EXTI0_CallBack)(void); //global pointer to function
void (* EXTI1_CallBack)(void); //global pointer to function

void MEXTI_voidInit(void)
{
	#if 	EXTI_SENSE_MODE	== EXTI_FALLING
			SET_BIT(EXTI->FTSR,EXTI_LINE);
	#elif	EXTI_SENSE_MODE	== EXTI_RISING
			SET_BIT(EXTI->RTSR,EXTI_LINE);
	#elif	EXTI_SENSE_MODE	== EXTI_IOC //ysht8al m3 rising w faling
			SET_BIT(EXTI->FTSR,EXTI_LINE);	
			SET_BIT(EXTI->RTSR,EXTI_LINE);
	#else
		#error "wrong choice of external sense mode"
		
	#endif

	CLR_BIT(EXTI-> IMR,EXTI_LINE);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8LineID	, u8 Copy_u8LineID)
{
	Switch
	{
		case EXTI_FALLING	:SET_BIT(EXTI->FTSR,EXTI_LINE) ;		
							 CLR_BIT(EXTI->RTSR,EXTI_LINE) ;		break;
		
		case EXTI_RISING	:SET_BIT(EXTI->RTSR,EXTI_LINE) ;		
							 CLR_BIT(EXTI->FTSR,EXTI_LINE) ;		break;
							 
		case EXTI_IOC		:SET_BIT(EXTI->RTSR,EXTI_LINE) ;	
							 SET_BIT(EXTI->FTSR,EXTI_LINE) ; 		break;
	}
	/* enable Interrupt Line*/
	SET_BIT(EXTI-> IMR,EXTI_LINE);
}

void MEXTI_voidEnable(u8 Copy_u8LineID)
{
	SET_BIT(EXTI-> IMR,Copy_u8LineID);
}
void MEXTI_voidDisable(u8 Copy_u8LineID)
{
	CLR_BIT(EXTI-> IMR,Copy_u8LineID);
}
void MEXTI_voidSetSoftwareTrigger(u8 Copy_u8LineID)
{
	SET_BIT(EXTI-> SWIER ,Copy_u8LineID );
}
/*here write ISR function for a certain interrupt*/
/*8yr el rakam fe sem el function to change the interrupt source*/
void EXTI0_IRQHandler(void) //lazem tkon bnafs el esm dah belzabt
{
	EXTI0_CallBack();
}

void EXTI1_IRQHandler(void) //lazem tkon bnafs el esm dah belzabt
{
	EXTI1_CallBack():
}

void EXTI0_voidSetCallBack(void (*pf)(void))
{
	EXTI0_CallBack = pf;
	SET_BIT(EXTI -> PR , EXTI_LINE0);
}
void EXTI1_voidSetCallBack(void (*pf)(void))
{
	EXTI1_CallBack = pf;
	SET_BIT(EXTI -> PR , EXTI_LINE1);
}