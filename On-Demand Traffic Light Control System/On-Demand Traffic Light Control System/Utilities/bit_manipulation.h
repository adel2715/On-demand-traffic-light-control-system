/*
 * Macros.h
 *
 * Created: 10/6/2022 9:17:06 PM
 *  Author: Adel
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(port, pin)		(port |= (1U<<pin))				
#define CLEAR_BIT(port, pin)	(port &= (~(1U<<pin)))	
#define TOGGLE_BIT(port, pin)	(port ^= (1U<<pin))
#define GET_BIT(port, pin)		((port & (1U<<pin)) >> pin)



#endif /* MACROS_H_ */