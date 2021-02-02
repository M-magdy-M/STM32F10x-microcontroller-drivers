/************************************************************************************/
/* AUTHOR	:	Mohamed Magdy														*/
/* VERSION	:	V02																	*/
/* DATE		:	2 FEB 2021															*/
/************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*choose clock source (HSI  - HSE - PLL)*/
#define CLOCK_SOURCE	HSI
//choose PLL source (HSE - HALF_HSE - HALF_HSI)
#define PLL_SOURCE	HSI
//AHB prescalar (7:15)
#define AHB_PRESCALER	7
//APB1 prescalar (3:7)
#define APB1_PRESCALER	3
//APB2 prescalar (3:7)
#define APB2_PRESCALER	3
//PLL multiplication factor(0-15)
#define PLL_MUL		0
/* if you are using external clock choose (RC - CRYSTAL)*/
#define EXTERNAL_CLk_TYPE		RC
/*choose (Enable - DISABLE)*/
#define RCC_SECURITY_SYSTEM		ENABLE


#endif
