/*
 * main.c
 *
 *  Created on: Apr 30, 2023
 *      Author: Hesha
 */


#include "external_interrupt.h"
#include "decoder_for_six_sevenSegments.h"
#include "timer1.h"





int main(){

	EXTERNAL_INTERRUPT_int0_init();
	EXTERNAL_INTERRUPT_int1_init();
	EXTERNAL_INTERRUPT_int2_init();

	TIMER1_init();

	DECODER_sevSeg_init();

	for(;;){
		if(counters[0]==10){// _ _  _ _ | _ _  _ _ | _ _ _/_
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

		DECODER_display_multiplixed_7seg();
//		PORTA = 0xff;
//		write_decoder_7_seg(0);
	}

}
