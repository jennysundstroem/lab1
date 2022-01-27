/*
 * CFile1.c
 *
 * Created: 2022-01-26 15:12:18
 *  Author: Elvira Forslund Widenroth & Jenny Sundström
 */ 

#include <avr/io.h>
#include <stdint-gcc.h>

uint16_t pressed = 0;							//flags if joystick is pressed or not


int joystick() {
	
	uint16_t bitflag = (PINB & (1<<7));			//retrieves input from bit 7 from PINB
	
	if (bitflag == 0 && pressed == 0) {			//joystick is activated and currently not pressed
		pressed = 1;							
		return 1;								//stops busy waiting to switch registers
	}
	else if (bitflag == 0 && pressed == 1) {	//joystick is activated and pressed, continue without switching
		return 0;
	}
	else {										//joystick not activated, pressed is switched to low, continue without switching
		pressed = 0;
		return 0;
	}
}