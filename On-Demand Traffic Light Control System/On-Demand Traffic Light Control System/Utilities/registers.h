/*
 * registers.h
 *
 * Created: 10/6/2022 9:26:24 PM
 *  Author: Adel
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"
//DIO registers

#define PORTA	*((volatile uint8_t*)0X3B)
#define DDRA	*((volatile uint8_t*)0X3A)
#define PINA	*((volatile uint8_t*)0X39)

#define PORTB	*((volatile uint8_t*)0X38)
#define DDRB	*((volatile uint8_t*)0X37)
#define PINB	*((volatile uint8_t*)0X36)

#define PORTD	*((volatile uint8_t*)0X32)
#define DDRD	*((volatile uint8_t*)0X31)
#define PIND	*((volatile uint8_t*)0X30)

//Timer/counter 0 registers

#define OCR0	*((volatile uint8_t*)0X5C)
#define TCCR0	*((volatile uint8_t*)0X53)
//TCCR0 bits numbers
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0


#define TCNT0	*((volatile uint8_t*)0X52)
#define TIMSK	*((volatile uint8_t*)0X59)
//TIMSK bits numbers
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0


#define TIFR	*((volatile uint8_t*)0X58)

//External interrupts registers

#define GICR	*((volatile uint8_t*)0X5B)
/* GICR bits numbers*/
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

#define MCUCR	*((volatile uint8_t*)0X55)
/* MCUCR bits numbers*/
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0


#define MCUCSR	*((volatile uint8_t*)0X54)

#define GIFR	*((volatile uint8_t*)0X5A)


#endif /* REGISTERS_H_ */