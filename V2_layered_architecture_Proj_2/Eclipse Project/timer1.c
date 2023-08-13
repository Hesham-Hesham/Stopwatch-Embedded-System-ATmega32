/*
 * timer.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Hesha
 */


#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer1.h"
#include "common_macros.h"
#include "std_types.h"



uint8 counters[6]={0}; //their representation in the 6 7-segs  _5_  _4_ | _3_  _2_ | _1_ _0_



ISR(TIMER1_COMPA_vect){
	counters[0]++;

	if(counters[0]==10){
		counters[0]=0;
	}
}

/*
 * Description : initializes timer 1 in compare mode
 *
 */
void TIMER1_init(void){

//	SET_BIT(TCCR1A,FOC1A) 			//non pwm mode
//
//	SET_BIT(TCCR1B,CS11);			//normal mode
//	SET_BIT(TCCR1B,CS10);			//normal mode
//	SET_BIT(TCCR1B,WGM12);			//normal mode
//
//	TCNT1  |= 0;						//current
//
//	OCR1A  |= 15625;					//compare value
//
//	SET_BIT(TIMSK,OCIE1A);			//t1 interrupt enable
//	SET_BIT(SREG,7);			//general interrupt enable (i-bit)

	TCCR1A |= (1<<FOC1A); 			//non pwm mode
	TCCR1B |= (1<<CS11) | (1<<CS10) | (1<<WGM12);//normal mode
	TCNT1  |= 0;					//current
	OCR1A  |= 15625;				//compare value
	TIMSK  |= (1<<OCIE1A);			//t1 interrupt enable
	SREG   |= (1<<7);				//general interrupt enable (i-bit)
}
