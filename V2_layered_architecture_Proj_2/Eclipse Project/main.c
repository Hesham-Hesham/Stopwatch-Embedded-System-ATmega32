/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Hesham
 */


#include "external_interrupt.h"
#include "decoder_for_six_sevenSegments.h"
#include "timer1.h"
#include "lcd.h"
//#include <avr/io.h>
//#include <util/delay.h>


int main(){

	EXTERNAL_INTERRUPT_int0_init();
	EXTERNAL_INTERRUPT_int1_init();
	EXTERNAL_INTERRUPT_int2_init();

	TIMER1_init();

	LCD_init();
	LCD_clearScreen();

	LCD_moveCursor(1,0);
	LCD_displayStringRowColumn(1, 0, "Hour   Min   Sec");
//	LCD_displayString("Hour   Min   Sec");
	LCD_moveCursor(0,0);

	//	for(;;){
	//
	//		LCD_intgerToString(i);
	//		i++;
	//		_delay_ms(1000);
	//
	//
	//	}
	for(;;){
		if(counters[0]==9){// _ _  _ _ | _ _  _ _ | _ _ _/_
			counters[0]=0;
			counters[1]++;
		}
		if(counters[1]==6){// _ _  _ _ | _ _  _ _ | _/_ _ _
			counters[1]=0;
			counters[2]++;
		}
		if(counters[2]==10){// _ _  _ _ | _ _  _/_ | _ _ _ _
			counters[2]=0;
			counters[3]++;
		}
		if(counters[3]==6){// _ _  _ _ | _/_  _ _ | _ _ _ _
			counters[3]=0;
			counters[4]++;
		}
		if(counters[4]==10){// _ _  _/_ | _ _  _ _ | _ _ _ _
			counters[4]=0;
			counters[5]++;
		}
		if(counters[5]==10){// _/_  _ _ | _ _  _ _ | _ _ _ _

			//stopwatch's maximum time was reached
			counters[0]=0;
			counters[1]=0;
			counters[2]=0;
			counters[3]=0;
			counters[4]=0;
			counters[5]=0;
		}

		LCD_intgerToString(counters[5]);
		LCD_intgerToString(counters[4]);
		LCD_displayString("  :  ");

		LCD_intgerToString(counters[3]);
		LCD_intgerToString(counters[2]);
		LCD_displayString("  : ");

		LCD_intgerToString(counters[1]);
		LCD_intgerToString(counters[0]);
		LCD_displayString(" ");

		LCD_moveCursor(0,0);

	}

}
