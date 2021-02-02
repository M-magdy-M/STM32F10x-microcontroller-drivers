/************************************************************************************/
/* AUTHOR	:	Mohamed Magdy														*/
/* VERSION	:	V02																	*/
/* DATE		:	2 FEB 2021															*/
/************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define ENABLE 			1
#define DISABLE 		0


#define RCC_Base_address 		0x4002 1000

#define RCC_CR					*((volatile u32*)(RCC_Base_address+0x00))
#define RCC_CFGR				*((volatile u32*)(RCC_Base_address+0x04))
#define RCC_CIR					*((volatile u32*)(RCC_Base_address+0x08))
#define RCC_APB2RSTR			*((volatile u32*)(RCC_Base_address+0x0c))
#define RCC_APB1RSTR			*((volatile u32*)(RCC_Base_address+0x10))
#define RCC_AHBENR				*((volatile u32*)(RCC_Base_address+0x14))
#define RCC_APB2ENR				*((volatile u32*)(RCC_Base_address+0x18))
#define RCC_APB1ENR				*((volatile u32*)(RCC_Base_address+0x1c))
#define RCC_BDCR				*((volatile u32*)(RCC_Base_address+0x20))
#define RCC_CSR					*((volatile u32*)(RCC_Base_address+0x24))

#endif