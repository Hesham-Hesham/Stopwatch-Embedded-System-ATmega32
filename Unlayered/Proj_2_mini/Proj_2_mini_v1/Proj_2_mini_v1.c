/*
 * Proj_2_mini_v1.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Hesha
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


//#define write_decoder_7_seg(num) PORTC=((num)&0x0F)|(PORTC&0xF0)
void write_decoder_7_seg(unsigned char num){ //decoder is connected to first 4 bits of C (0,1,2,3)
		PORTC = (num&0x0F)|(PORTC&0xF0);
}

unsigned char counters[6]={0}; //their representation in the 6 7-segs  _5_  _4_ | _3_  _2_ | _1_ _0_
unsigned char i=0;

void ext_int0_init(void){

	DDRD &= ~(1<<2);		//input
	PORTD |= (1<<2);		//internal pullup
	MCUCR |= (1<<ISC01);	//falling edge
	GICR |= (1<<INT0);		//external interrupt enable
	SREG  |= (1<<7);  ; 	//general interrupt enable

}

void ext_int1_init(void){

	DDRD &= ~(1<<3);		//input
	MCUCR |= (1<<ISC11) | (1<<ISC10); //rising edge
	GICR |= (1<<INT1);		//external interrupt enable
	SREG  |= (1<<7);  	 	//general interrupt enable
}

void ext_int2_init(void){

	DDRB &= ~(1<<2);		//input
	PORTB |= (1<<2);		//internal pullup
	//ISC2 in MCUCSR -->0	//falling edge
	GICR |= (1<<INT2);		//external interrupt enable
	SREG  |= (1<<7);  		//general interrupt enable

}

void timer1_init(void){

	TCCR1A |= (1<<FOC1A); 			//non pwm mode
	TCCR1B |= (1<<CS11) | (1<<CS10) | (1<<WGM12);//normal mode
	TCNT1  |= 0;					//current
	OCR1A  |= 15625;				//compare value
	TIMSK  |= (1<<OCIE1A);			//t1 interrupt enable
	SREG   |= (1<<7);				//general interrupt enable (i-bit)
}


ISR(INT0_vect){
	//reset stopwatch
	for(i=0;i<6;i++){
		counters[i]=0;				//reset all digits
	}
	TCNT1  |= 0;					//reset current ticks
}

ISR(INT1_vect){
	//pause stopwatch
	TIMSK  &= ~(1<<OCIE1A);			//t1 interrupt disable
}

ISR(INT2_vect){
	//resume stopwatch
	TIMSK  |= (1<<OCIE1A);			//t1 interrupt enable
	TCNT1  |= 0;					//reset current ticks

}

ISR(TIMER1_COMPA_vect){
	counters[0]++;

}

//common anode vcc-->on
void display_multiplixed_7seg(void){

//	PORTA &= 0xC0;			// 0,1,2,3,4,5 of portA = 0 -----> all six 7-segs off

	for(i=0;i<6;i++){
		PORTA |= (1<<i);	//7-seg number (i) is on
		write_decoder_7_seg(counters[i]);	//display the number (i) on 7-seg number (i)
		_delay_ms(1);
		PORTA &= 0xC0;		// 0,1,2,3,4,5 of portA = 0 -----> all six 7-segs off
	}


}

int main(){

	ext_int0_init();
	ext_int1_init();
	ext_int2_init();
	timer1_init();

	DDRC |= 0x0F; //4 pins for decoder


	DDRA |= 0xC0; //0,1,2,3,4,5 of portA are output

	PORTA &= 0xC0;			// 0,1,2,3,4,5 of portA = 0 -----> all six 7-segs off

	for(;;){
		if(counters[0]==10){// _ _  _ _ | _ _  _ _ | _ _ _/_
			counters[0]=0;
			counters[1]++;
		}
		if(counters[1]==10){// _ _  _ _ | _ _  _ _ | _/_ _ _
			counters[1]=0;
			counters[2]++;
		}
		if(counters[2]==10){// _ _  _ _ | _ _  _/_ | _ _ _ _
			counters[2]=0;
			counters[3]++;
		}
		if(counters[3]==10){// _ _  _ _ | _/_  _ _ | _ _ _ _
			counters[3]=0;
			counters[4]++;
		}
		if(counters[4]==10){// _ _  _/_ | _ _  _ _ | _ _ _ _
			counters[4]=0;
			counters[5]++;
		}
		if(counters[5]==10){// _/_  _ _ | _ _  _ _ | _ _ _ _
			counters[5]=0;
		}

		display_multiplixed_7seg();
//		PORTA = 0xff;
//		write_decoder_7_seg(0);
	}

}
