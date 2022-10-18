/*
 * button.h
 *
 * Created: 10/6/2022 9:18:10 PM
 *  Author: Adel
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../Utilities/types.h"

typedef struct ST_button_t{
	uint8_t port;
	uint8_t pin;
	volatile uint8_t value; 
}ST_button_t;
	
void button_init(ST_button_t button); //initialize selected pin for button as input DIO
void button_read(ST_button_t *button); // get the current value on button pin HIGH or LOW (1 or 0)
	




#endif /* BUTTON_H_ */