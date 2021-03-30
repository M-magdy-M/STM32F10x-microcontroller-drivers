/************************************************************************************/
/* AUTHOR	:	Mohamed Magdy														*/
/* VERSION	:	V02																	*/
/* DATE		:	3 FEB 2021															*/
/************************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_U8_HIGH	1
#define GPIO_U8_LOW		0

#define GPIO_PORT_A		1
#define GPIO_PORT_B		2
#define GPIO_PORT_C		3

#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15
/*********************************MODES***************************/
#define GPIO_INPUT_ANALOG					0b0000
#define GPIO_INPUT_FLOATING					0b0100
#define GPIO_INPUT_PULL_UP_DOWN				0b1000

#define GPIO_OUTPUT_10MHZ_PP				0b0001				/*push pull*/
#define GPIO_OUTPUT_10MHZ_OD				0b0101 				/*open drain*/
#define GPIO_OUTPUT_10MHZ_AFPP				0b1001				/*alternative function push pull*/
#define GPIO_OUTPUT_10MHZ_AFOD				0b1101				/*alternative function open drain*/

#define GPIO_OUTPUT_2MHZ_PP					0b0010				/*push pull*/
#define GPIO_OUTPUT_2MHZ_OD					0b0110 				/*open drain*/
#define GPIO_OUTPUT_2MHZ_AFPP				0b1010				/*alternative function push pull*/
#define GPIO_OUTPUT_2MHZ_AFOD				0b1110				/*alternative function open drain*/

#define GPIO_OUTPUT_50MHZ_PP				0b0011				/*push pull*/
#define GPIO_OUTPUT_50MHZ_OD				0b0111 				/*open drain*/
#define GPIO_OUTPUT_50MHZ_AFPP				0b1011				/*alternative function push pull*/
#define GPIO_OUTPUT_50MHZ_AFOD				0b1111				/*alternative function open drain*/
/*****************************************************************/

void	MGPIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode);
void	MGPIO_voidSetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);
u8		MGPIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);

void	MGPIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Mode);
//this function only used with PORT A and PORT B and >"NOT"< PORT C
void	MGPIO_voidSetPortValue(u8 Copy_u8PortID,u16 Copy_u16Value);
#endif
