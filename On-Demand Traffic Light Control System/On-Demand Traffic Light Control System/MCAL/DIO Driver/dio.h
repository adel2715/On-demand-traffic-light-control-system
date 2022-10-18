/*
 * dio.h
 *
 * Created: 10/6/2022 9:19:28 PM
 *  Author: Adel
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/types.h"

//Ports names defines
#define PORT_A	'A'
#define PORT_B	'B'
#define PORT_C	'C'
#define PORT_D	'D'

//Directions defines
#define IN	0
#define OUT	1

//Values defines
#define LOW		0
#define HIGH	1



//Functions prototypes
void DIO_init(uint8_t port, uint8_t pin, uint8_t dir);				//initialize DIO pin in port and passed direction IN or OUT
void DIO_write(uint8_t port, uint8_t pin, uint8_t value);			//write LOW or HIGH values on the passed pin 
void DIO_toggle(uint8_t port, uint8_t pin);							//toggle current pin state
void DIO_read(uint8_t port, uint8_t pin, volatile uint8_t *value);	// get the current value exist on the pin





#endif /* DIO_H_ */