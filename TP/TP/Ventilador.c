/*
 * Ventilador.c
 *
 * Created: 26-Jul-21 7:46:54 PM
 *  Author: fedea
 */ 

#include "Ventilador.h"

void VENTILADOR_Init(){
	//setea pin pb0 como escritura
	DDRB |= (1<<PORTB0);

}

void VENTILADOR_TurnOff(){
	//apaga el led conecatdo a pb0
	PORTB &= ~(1<<PORTB0);
}

void VENTILADOR_TurnOn(){
	//prende el led conectado a pb0
	PORTB |= (1<<PORTB0);
}