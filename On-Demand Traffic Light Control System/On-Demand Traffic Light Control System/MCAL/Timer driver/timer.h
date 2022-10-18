/*
 * timer.h
 *
 * Created: 10/6/2022 9:20:18 PM
 *  Author: Adel
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/types.h"

//define timer0 available modes
typedef enum EN_timer0Mode_t {
	NORMAL, CTC, FAST_PWM, PHASE_CORRECT_PWM
	}EN_timer0Mode_t;
	
void timer0_start(EN_timer0Mode_t mode);	//initialize timer zero to passed mode
uint32_t timer0_millis(void);				//return elapsed timer starting from power on in milli seconds




#endif /* TIMER_H_ */