/*
 * Calefactor.c
 *
 * Created: 26-Jul-21 7:47:10 PM
 *  Author: fedea
 */ 


#include "Calefactor.h"


void CALEFACTOR_Init(){
	//setea pin pb1 como escritura
	DDRB |= (1<<PORTB1);
}

void CALEFACTOR_TurnOff(){
	//apaga el led conecatdo a pb1
	PORTB &= ~(1<<PORTB1);
}

void CALEFACTOR_TurnOn(){
	PORTB |= (1<<PORTB1);
	//prende el led conectado a pb1
}