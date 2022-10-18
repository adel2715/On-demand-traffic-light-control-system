/*
 * app.h
 *
 * Created: 10/6/2022 9:17:43 PM
 *  Author: Adel
 */ 


#ifndef APP_H_
#define APP_H_

typedef enum EN_ledColor_t{
	CAR_GREEN, CAR_YELLOW, CAR_RED, PEDESTRIAN_GREEN, PEDESTRIAN_YELLOW, PEDESTRIAN_RED
}EN_ledColor_t;
	
void app_init(void);
void app_start(void);
void EXT_INT0_enable(void);


#endif /* APP_H_ */