/*
 * button.c
 *
 * Created: 10/6/2022 9:18:32 PM
 *  Author: Adel
 */ 
#include "button.h"
#include "../../MCAL/DIO Driver/dio.h"

void button_init(ST_button_t button){
	DIO_init(button.port, button.pin, IN);
}

void button_read(ST_button_t *button){
	DIO_read(button->port, button->pin, &button->value);
}
