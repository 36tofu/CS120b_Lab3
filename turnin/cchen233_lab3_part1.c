/*	Author: Christopher Chen
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 1
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs

	unsigned char totalOnes = 0x00; // Temporary variable to hold the total weight

    /* Insert your solution below */
    while (1) {
	for(unsigned char i = 0; i < 8; i++){
		totalOnes += (PINA & (0x01 << i)) >> i;
		totalOnes += (PINB & (0x01 << i)) >> i;
	}
	PORTC = totalOnes;
    }
    
    return 1;
}
