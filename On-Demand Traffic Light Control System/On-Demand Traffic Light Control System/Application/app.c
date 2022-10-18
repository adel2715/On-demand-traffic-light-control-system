/*
 * app.c
 *
 * Created: 10/6/2022 9:17:55 PM
 *  Author: Adel
 */ 

//include required drivers
#include "app.h"
#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Interrupt Lib/interrupts.h"
#include "../MCAL/Timer driver/timer.h"
#include "../ECUAL/Button/button.h"
#include "../ECUAL/LED/led.h"
#include "../Utilities/bit_manipulation.h"
#include "../Utilities/registers.h"
#include "../Utilities/types.h"

//define global variables needed
#define _NORMAL		0
#define _PEDESTRIAN	1

volatile uint8_t mode;

EN_ledColor_t carCurrentLed, carPreviousLed, pedestrianCurrentLed, pedestrianPreviousLed;

volatile uint32_t previousTime, currentTime, blinkPreviousTime, pressTickTime;
//define pedestrian request button on pin INT0
ST_button_t pedestrianButton = {PORT_D, 2, 0};
	
//define card leds
ST_led_t carGreenLed = {PORT_A, 0}, carYellowLed = {PORT_A, 1}, carRedLed = {PORT_A, 2};
	
//define pedestrian leds
ST_led_t pedestrianGreenLed = {PORT_B, 0}, pedestrianYellowLed = {PORT_B, 1}, pedestrianRedLed = {PORT_B, 2};
	
void app_init(void){
	// set initial mode to Normal
	mode = _NORMAL;
	
	
	
	//initialize button pin as input
	button_init(pedestrianButton);
	
	//initialize car leds pins as outputs
	LED_init(carGreenLed);
	LED_init(carYellowLed);
	LED_init(carRedLed);
	
	
	//initialize pedestrian leds pins as output
	LED_init(pedestrianGreenLed);
	LED_init(pedestrianYellowLed);
	LED_init(pedestrianRedLed);
	
	
	//set initial state car led to green and pedestrian led to red
	carCurrentLed = CAR_GREEN;
	carPreviousLed = CAR_YELLOW;
	
	pedestrianCurrentLed = PEDESTRIAN_RED;
	pedestrianPreviousLed = PEDESTRIAN_YELLOW;
	
	//change leds states to match above initialization leds off as initial state
	LED_on(carGreenLed);
	LED_off(carYellowLed);
	LED_off(carRedLed);
	LED_off(pedestrianGreenLed);
	LED_off(pedestrianYellowLed);
	LED_on(pedestrianRedLed);
	
	//initialize timer0 to generate delays in compare match mode
	timer0_start(CTC);
	
	//enable external interrupts for pin INT0
	EXT_INT0_enable();
	
	//enable general interrupts
	sei();
	
	
	
	//set previous time passed to zero
	previousTime = 0;
	
	blinkPreviousTime = 0;
	
	pressTickTime = 0;
	
	
}

void app_start(void){
	
	while(1){
		//get current value of timers in milli seconds
		currentTime = timer0_millis();
		
		//normal mode
		if(mode == _NORMAL){
			//pedestrian red led is on
			//car green led is on for 5 seconds
			//after 5 seconds passed card green led turned off
			//and car yellow led will blinking for 5 seconds
			//after 5 seconds passed car yellow led turned off and car red led turned on
			//after 5 seconds passed card red led turned off
			//and car yellow led will blinking for 5 seconds
			//after 5 seconds passed car yellow led turned off and car green led turned on
			if(currentTime >= (previousTime+5000)){
				switch(carCurrentLed){
					case CAR_GREEN:
					carCurrentLed = CAR_YELLOW;
					carPreviousLed = CAR_GREEN;
					LED_off(carGreenLed);
					LED_on(carYellowLed);
					break;
					
					case CAR_YELLOW:
					if(carPreviousLed == CAR_GREEN){
						carCurrentLed = CAR_RED;
						carPreviousLed = CAR_YELLOW;
						LED_off(carYellowLed);
						LED_on(carRedLed);
					}else if(carPreviousLed == CAR_RED){
						carCurrentLed = CAR_GREEN;
						carPreviousLed = CAR_YELLOW;
						LED_off(carYellowLed);
						LED_on(carGreenLed);
					}else{
						//Error handling
					}
					
					break;
					
					case CAR_RED:
					carCurrentLed = CAR_YELLOW;
					carPreviousLed = CAR_RED;
					LED_off(carRedLed);
					LED_on(carYellowLed);
					break;
					
					default:
					carCurrentLed = CAR_GREEN;
					carPreviousLed = CAR_YELLOW;
					LED_off(carYellowLed);
					LED_on(carGreenLed);
					break;
					
				}
				
				previousTime = currentTime;
				blinkPreviousTime = currentTime;
			}
			
		}else if(mode == _PEDESTRIAN){	//pedestrian mode
			
			//Change from normal mode to pedestrian mode when the pedestrian button is pressed.
			//If pressed when the cars' Red LED is on, 
			//the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds,
			//this means that pedestrians can cross the street while the pedestrian's Green LED is on.
			if(carCurrentLed == CAR_RED && pedestrianCurrentLed == PEDESTRIAN_RED){
				LED_off(pedestrianRedLed);
				pedestrianCurrentLed = PEDESTRIAN_GREEN;
				pedestrianPreviousLed = PEDESTRIAN_RED;
				LED_on(pedestrianGreenLed);
				previousTime = currentTime;
				blinkPreviousTime = currentTime;
			}
			//If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, 
			//the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, 
			//then the cars' Red LED and pedestrian Green LEDs are on for five seconds, 
			//this means that pedestrian must wait until the Green LED is on.
			else if((carCurrentLed == CAR_GREEN ||carCurrentLed == CAR_YELLOW) && pedestrianCurrentLed == PEDESTRIAN_RED){
				pedestrianPreviousLed = PEDESTRIAN_RED;
				pedestrianCurrentLed = PEDESTRIAN_YELLOW;
				carCurrentLed = CAR_YELLOW;
				carPreviousLed = CAR_GREEN;
				LED_off(carGreenLed);
				LED_off(carRedLed);
				LED_on(carYellowLed);
				LED_on(pedestrianYellowLed);
				previousTime = currentTime;
				blinkPreviousTime = currentTime;
			}
			
			
			
			//At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
			//After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
			//Traffic lights signals are going to the normal mode again.
			if(currentTime >= (previousTime+5000)){
				switch(pedestrianCurrentLed){
					case PEDESTRIAN_GREEN:
					LED_off(carRedLed);
					LED_on(carYellowLed);
					LED_on(pedestrianYellowLed);
					carCurrentLed = CAR_YELLOW;
					carPreviousLed = CAR_RED;
					pedestrianCurrentLed = PEDESTRIAN_YELLOW;
					pedestrianPreviousLed = PEDESTRIAN_GREEN;
					
					break;
					
					case PEDESTRIAN_YELLOW:
					if(pedestrianPreviousLed == PEDESTRIAN_GREEN){
						LED_off(pedestrianGreenLed);
						LED_off(pedestrianYellowLed);
						LED_on(pedestrianRedLed);
						LED_off(carYellowLed);
						LED_on(carGreenLed);
						pedestrianCurrentLed = PEDESTRIAN_RED;
						pedestrianPreviousLed = PEDESTRIAN_YELLOW;
						carCurrentLed = CAR_GREEN;
						carPreviousLed = CAR_YELLOW;
						
						mode = _NORMAL;
					}else if(pedestrianPreviousLed == PEDESTRIAN_RED){
						LED_off(pedestrianRedLed);
						LED_off(pedestrianYellowLed);
						LED_on(pedestrianGreenLed);
						LED_off(carYellowLed);
						LED_on(carRedLed);
						pedestrianCurrentLed = PEDESTRIAN_GREEN;
						pedestrianPreviousLed = PEDESTRIAN_YELLOW;
						carCurrentLed = CAR_RED;
						carPreviousLed = CAR_YELLOW;
						
					}
					
					break;
					
					default:
					break;
				}
				
				previousTime = currentTime;
				blinkPreviousTime = currentTime;
			}
			
			
		}
		
		//check the state of button after one second from interrupt execution to handel long press
		
		if(pedestrianButton.value == 1 && (currentTime >= (pressTickTime+1000))){
			button_read(&pedestrianButton);
			if(pedestrianButton.value == 0){
				mode = _PEDESTRIAN;
			}else{
				pedestrianButton.value = 0;
			}
		}
		
		// toggle yellow leds each one second if the current led is yellow
		if(currentTime >= (blinkPreviousTime+1000)){
			if(mode == _NORMAL && carCurrentLed == CAR_YELLOW){
				LED_toggle(carYellowLed);
			}else if(mode == _PEDESTRIAN && carCurrentLed == CAR_YELLOW && pedestrianCurrentLed == PEDESTRIAN_YELLOW){
				LED_toggle(carYellowLed);
				LED_toggle(pedestrianYellowLed);
			}
			
			blinkPreviousTime = currentTime;
		}
		
		
	}
}

void EXT_INT0_enable(void){
	
	//interrupt sense on raising edge on INT0 pin
	SET_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
	SET_BIT(GICR, INT0);
}

ISR(EXT_INT_0){
	if(mode == _NORMAL){
		pedestrianButton.value = 1;
		pressTickTime = timer0_millis();
	}
}