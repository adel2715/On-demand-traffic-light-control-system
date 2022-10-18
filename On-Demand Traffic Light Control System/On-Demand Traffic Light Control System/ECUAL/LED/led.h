/*
 * led.h
 *
 * Created: 10/6/2022 9:18:53 PM
 *  Author: Adel
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../Utilities/types.h"


typedef struct ST_led_t{
	uint8_t port;
	uint8_t pin;
}ST_led_t;

void LED_init(ST_led_t led);	//initialize selected pin for led as output DIO
void LED_on(ST_led_t led);		//turn on the led by putting logic one on the led pin
void LED_off(ST_led_t led);		//turn off the led by putting logic zero on the led pin
void LED_toggle(ST_led_t led);	//toggle current state of led

#endif /* LED_H_ */