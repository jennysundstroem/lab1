/*
 * Lab_1.c
 *
 * Created: 2022-01-24 10:56:30
 * Author : Elvira Forslund Widenroth & Jenny Sundstr�m
 */ 

#include <avr/io.h>
//#include "LCD_Display.c"


int main(void)
{
	CLKPR = 0x80;
	CLKPR = 0x00;
	/*Replace with your application code */
	LCD_Init();
	while(1){
	//primes();
	//blink();
	//button();
	combine();
	//writeChar(0,0);
	//writeChar(2,1);
	//writeChar(4,2);
	//writeChar(8,3);
	//writeChar(9,4);
	//writeChar(1,5);
	
	
	}

}



