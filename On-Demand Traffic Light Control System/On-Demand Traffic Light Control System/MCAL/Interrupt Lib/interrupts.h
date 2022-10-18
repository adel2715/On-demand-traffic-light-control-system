/*
 * interrupts.h
 *
 * Created: 10/6/2022 9:20:00 PM
 *  Author: Adel
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#define EXT_INT_0	__vector_1
#define TIMER0_OVF	__vector_11
#define TIMER0_COMP	__vector_10
//set global interrupts

#define sei()	__asm__ __volatile__ ("sei" ::: "memory")

//clear global interrupts

#define cli()	__asm__ __volatile__ ("cli" ::: "memory")

//ISR definition
#define ISR(INT_VECTOR)	void INT_VECTOR(void) __attribute__ ((signal,used));\
void INT_VECTOR(void)



#endif /* INTERRUPTS_H_ */