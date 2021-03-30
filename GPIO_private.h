/************************************************************************************/
/* AUTHOR	:	Mohamed Magdy														*/
/* VERSION	:	V02																	*/
/* DATE		:	3 FEB 2021															*/
/************************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define PORT_A_BASE_ADDRESS			0x40010800
#define PORT_B_BASE_ADDRESS			0x40010C00
#define PORT_C_BASE_ADDRESS			0x40011000
					/*GPIO A registers addresses*/
#define GPIO_A_CRL					*((volatile u32 *)(0x40010800))
#define GPIO_A_CRH					*((volatile u32 *)(0x40010800+0x04))
#define GPIO_A_IDR					*((volatile u32 *)(0x40010800+0x08))
#define GPIO_A_ODR					*((volatile u32 *)(0x40010800+0x0c))
#define GPIO_A_BSRR					*((volatile u32 *)(PORT_A_BASE_ADDRESS+0x10))
#define GPIO_A_BRR					*((volatile u32 *)(PORT_A_BASE_ADDRESS+0x14))
#define GPIO_A_LCKR					*((volatile u32 *)(PORT_A_BASE_ADDRESS+0x18))
					/*GPIO B registers addresses*/
#define GPIO_B_CRL					*((volatile u32 *)(PORT_B_BASE_ADDRESS+0x00))
#define GPIO_B_CRH					*((volatile u32 *)(PORT_B_BASE_ADDRESS+0x04))
#define GPIO_B_IDR					*((volatile u32 *)(PORT_B_BASE_ADDRESS+0x08))
#define GPIO_B_ODR					*((volatile u32 *)(PORT_B_BASE_ADDRESS+0x0c))
#define GPIO_B_BSRR					*((volatile u32 *)(PORT_B_BASE_ADDRESS+0x10))
#define GPIO_B_BRR					*((volatile u32 *)(PORT_B_BASE_ADDRESS+0x14))
#define GPIO_B_LCKR					*((volatile u32 *)(PORT_B_BASE_ADDRESS+0x18))
					/*GPIO C registers addresses*/
#define GPIO_C_CRL					*((volatile u32 *)(PORT_C_BASE_ADDRESS+0x00))
#define GPIO_C_CRH					*((volatile u32 *)(PORT_C_BASE_ADDRESS+0x04))
#define GPIO_C_IDR					*((volatile u32 *)(PORT_C_BASE_ADDRESS+0x08))
#define GPIO_C_ODR					*((volatile u32 *)(PORT_C_BASE_ADDRESS+0x0c))
#define GPIO_C_BSRR					*((volatile u32 *)(PORT_C_BASE_ADDRESS+0x10))
#define GPIO_C_BRR					*((volatile u32 *)(PORT_C_BASE_ADDRESS+0x14))
#define GPIO_C_LCKR					*((volatile u32 *)(PORT_C_BASE_ADDRESS+0x18))

#endif