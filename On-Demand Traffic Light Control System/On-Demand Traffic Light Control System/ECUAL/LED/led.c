/*
 * led.c
 *
 * Created: 10/6/2022 9:18:42 PM
 *  Author: Adel
 */ 
#include "led.h"
#include "../../MCAL/DIO Driver/dio.h"

void LED_init(ST_led_t led){
	DIO_init(led.port, led.pin, OUT);
}

void LED_on(ST_led_t led){
	DIO_write(led.port, led.pin, HIGH);
}

void LED_off(ST_led_t led){
	DIO_write(led.port, led.pin, LOW);
}

void LED_toggle(ST_led_t led){
	DIO_toggle(led.port, led.pin);
}

