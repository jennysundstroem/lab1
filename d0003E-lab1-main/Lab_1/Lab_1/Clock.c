/*
 * Clock.c
 *
 * Created: 2022-01-25 13:43:42
 *  Author: Elvira Forslund Widenroth & Jenny Sundström
 */ 

#include <avr/io.h>
#include <stdint-gcc.h>

uint16_t internalClock = 0;							//internal clock
uint16_t clockFactor = 8000000/256;					//increase value
uint16_t blinkFlag = 0;								//keeps track of blink on/off


//internal clock for blinking in steady pace, 1 Hz
int clock(){

        if(TCNT1 >= internalClock && blinkFlag == 0){						//check if its time to blink
        blinkFlag = 1;
            if((internalClock + clockFactor) > 0xFFFFF){					//if next time increase added reaches max value of clock
            
                internalClock = ((internalClock + clockFactor) - 0xFFFFF);	//if max value is reached, update internal clock and subtract max value to get accurate value after reset
            }else{
                internalClock = (internalClock + clockFactor);				//increase as normal if max is not reached
            }
            return 1;														//stops busy waiting and turn on/off blink
        }
    if (TCNT1 < internalClock){												//if it is not time to blink
        blinkFlag = 0;														//continue and do not blink
        return 0;
    }
}