/*
 * Part4.c
 *
 * Created: 2022-01-26 16:18:26
 *  Author: Elvira Forslund Widenroth & Jenny Sundström
 */ 

#include <avr/io.h>
#include <stdint-gcc.h>

//initialization
void initpart4() {
	TCCR1B = (1<<CS12) | (0<<CS11) | (0<<CS10);
	PORTB = PORTB | (1 << 7);
}

//primes, blink and button combined without interrupts 
void combine() {
	
	
	initpart4();

	uint16_t clockFactor = 8000000/256;
	uint16_t internalClock = 0;
	uint16_t blinkFlag = 0;
	uint16_t bitFlag = 0;
	uint16_t pressed = 0;
	
	long n = 1;
	
	while (1) {
	
	
	if (is_prime(n)) {													//first print prime number
		writeLong(n);													
	}
	
	if(TCNT1 >= internalClock && blinkFlag == 0){						//before next prime number do blinking
			blinkFlag = 1;
			
			if((internalClock + clockFactor) > 0xFFFFF){
			
				clockFactor = ((clockFactor + clockFactor) - 0xFFFFF);
			}else{
				internalClock = (internalClock + clockFactor);
			}
			if (LCDDR8 != 0) {
					LCDDR8 = 0x0;
			}else {
					LCDDR8 = 0x1;
				}
			}
	if (TCNT1 < internalClock){
		blinkFlag = 0;
	}

	uint16_t bitFlag = (PINB & (1<<7));									//before next prime number do joystick
	if (bitFlag == 0 && pressed == 0) {
		pressed = 1;
		
			if (LCDDR3 == 0)  {
				LCDDR3 =0x1;
				LCDDR13 = 0x0;
				
			}else {
				LCDDR3 = 0x0;
				LCDDR13 = 0x1;
			}
	}else if (bitFlag == 0 && pressed == 1) {
				
	}else{
			pressed = 0;
			}
		n++;															//increase number
	}
}
		