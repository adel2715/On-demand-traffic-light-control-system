/*
 * timer.c
 *
 * Created: 10/6/2022 9:20:28 PM
 *  Author: Adel
 */ 
#include "timer.h"
#include "../Interrupt Lib/interrupts.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"

static volatile uint32_t milli = 0;


void timer0_start(EN_timer0Mode_t mode){
	switch(mode){
		case NORMAL:
		//write Normal mode configuration code here
		break;
		case CTC:
		SET_BIT(TCCR0, WGM01);
		SET_BIT(TCCR0, CS01); //set prescaler = 8
		OCR0 = 249;
		SET_BIT(TIMSK, OCIE0);
		default:
		break;
	}
}

uint32_t timer0_millis(void){
	return milli;
}



ISR(TIMER0_COMP){
		milli += 2;
}