/*
 * c
 *
 * Created: 10/6/2022 9:19:38 PM
 *  Author: Adel
 */ 
#include "dio.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

void DIO_init(uint8_t port, uint8_t pin, uint8_t dir){
	switch(port){
		case PORT_A:
		if(dir == IN){
			CLEAR_BIT(DDRA, pin);
		}else if(dir == OUT){
			SET_BIT(DDRA, pin);
		}else{
			//error handling
		}
		break;
		case PORT_B:
		if(dir == IN){
			CLEAR_BIT(DDRB, pin);
			}else if(dir == OUT){
			SET_BIT(DDRB, pin);
			}else{
			//error handling
		}
		break;
		case PORT_D:
		if(dir == IN){
			CLEAR_BIT(DDRD, pin);
			}else if(dir == OUT){
			SET_BIT(DDRD, pin);
			}else{
			//error handling
		}
		break;
		default:
		break;
	}
}

void DIO_write(uint8_t port, uint8_t pin, uint8_t value){
	switch(port){
		case PORT_A:
		if(value == LOW){
			CLEAR_BIT(PORTA, pin);
			}else if(value == HIGH){
			SET_BIT(PORTA, pin);
			}else{
			//error handling
		}
		
		break;
		case PORT_B:
		if(value == LOW){
			CLEAR_BIT(PORTB, pin);
			}else if(value == HIGH){
			SET_BIT(PORTB, pin);
			}else{
			//error handling
		}
		break;
		case PORT_D:
		if(value == LOW){
			CLEAR_BIT(PORTD, pin);
			}else if(value == HIGH){
			SET_BIT(PORTD, pin);
			}else{
			//error handling
		}

		break;
		default:
		break;
	}
}

void DIO_toggle(uint8_t port, uint8_t pin){
	switch(port){
		case PORT_A:
		TOGGLE_BIT(PORTA, pin);
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB, pin);
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD, pin);
		break;
		default:
		break;
	}
}

void DIO_read(uint8_t port, uint8_t pin, volatile uint8_t *value){
	switch(port){
		case PORT_A:
		*value = GET_BIT(PINA, pin);
		break;
		case PORT_B:
		*value = GET_BIT(PINB, pin);
		break;
		case PORT_D:
		*value = GET_BIT(PIND, pin);
		break;
		default:
		break;
	}
}