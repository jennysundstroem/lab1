/*
 * Clock.c
 *
 * Created: 2022-01-25 13:43:42
 *  Author: Elvira Forslund Widenroth & Jenny Sundström
 */ 

#include <avr/io.h>
#include <stdint-gcc.h>

uint16_t clockFactor = 8000000/512;					//factor to manage blinking
uint16_t clockCount = 0;							//counter
uint16_t blinkFlag = 0;								//keeps track of blink on/off


int clock(){


	while(1){
		if(TCNT1 >= clockCount && blinkFlag == 0){						//check if its time to blink
			blinkFlag = 1;
			if((clockCount + clockFactor) > 0xFFFFF){					//if next time increase added reaches max value of clock
				
				clockCount = ((clockCount + clockFactor) - 0xFFFFF);   //if max value is reached, update internal clock and subtract max value to get accurate value after reset
				}else{
				clockCount = (clockCount + clockFactor);			   //increase as normal if max is not reached
				}
				return 1;											   //stops busy waiting and turn on/off blink
				}
		else if (TCNT1 < clockCount){								   //if it is not time to blink
			blinkFlag = 0;											   //continue and do not blink
			return 0;
				}
			}
	}

