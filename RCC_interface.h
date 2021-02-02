/************************************************************************************/
/* AUTHOR	:	Mohamed Magdy														*/
/* VERSION	:	V02																	*/
/* DATE		:	2 FEB 2021															*/
/************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define 		RCC_AHB					1
#define 		RCC_APB1				3
#define 		RCC_APB2				6

#define			HSI						1
#define			HSE						2
#define			PLL						3
#define			HALF_HSI				4
#define			HALF_HSE				5

#define			RC						1
#define			CRYSTAL					2

void RCC_voidInitiate(void);
void RCC_voidEnableClock(u8 Copy_u8BusID , u8 Copy_u8PerphiralID);
void RCC_voidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PerphiralID);
//Trim Value Default = 16
//this function will return HSICAL register value which is internal high speed clk
//put any value out of (0:32) to just return clk value/40K HZ
#endif
