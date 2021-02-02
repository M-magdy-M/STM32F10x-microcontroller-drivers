/************************************************************************************/
/* AUTHOR	:	Mohamed Magdy														*/
/* VERSION	:	V02																	*/
/* DATE		:	2 FEB 2021															*/
/************************************************************************************/


#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT_NO) (REG |= (1<<BIT_NO))
#define CLR_BIT(REG,BIT_NO) (REG &= ~(1<<BIT_NO))
#define TOGGLE_BIT(REG,BIT_NO) (REG ^= (1<<BIT_NO))
#define GET_BIT2(REG,BIT_NO) ((REG & (1<<BIT_NO))?1:0)
#define GET_BIT(REG,BIT_NO) ((REG>>BIT_NO)&1)


#endif