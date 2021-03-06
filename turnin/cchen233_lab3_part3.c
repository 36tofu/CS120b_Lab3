/*	Author: Christopher Chen
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00; // Configure port A's 8 pins as inputs
	DDRC = 0x00; PORTC = 0x00; // Configure port C's 8 pins as outputs

	unsigned char tempc = 0x00; // Temporary variable to hold the total weight
	unsigned char tempa = 0x00; // Temporary variable to hold the total weight

    /* Insert your solution below */
    while (1) {
	tempc = 0x00;
	tempa = PINA & 0x0F;

	if(tempa == 0)
		tempc = 0;
	else if(tempa <= 2)
		tempc = 0x20;
	else if(tempa <= 4)
		tempc = 0x30;
	else if(tempa <= 6)
		tempc = 0x38;
	else if(tempa <= 9)
		tempc = 0x3C;
	else if(tempa <= 12)
		tempc = 0x3E;
	else
		tempc = 0x3F;
	//check whether lower than 4
	if(tempa <= 4)
		tempc = tempc | 0x40;
	
	tempa = (PINA & 0x70) >> 4;
	if(tempa == 0x03)
		tempc = tempc | 0x80;
	else
		tempc = tempc & 0x7F;

	PORTC = tempc;
    }
    
    return 1;
}
