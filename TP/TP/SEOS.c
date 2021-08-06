/*
 * seos.c
 *
 * Created: 08-May-21 4:39:28 PM
 *  Author: fedea
 */ 

#include "seos.h"

volatile unsigned char FLAG_Sensor=0;
static unsigned char iCont=0;


void SEOS_Init(){
	//configuro Timer1 para interrupciones cada 100ms	
	OCR1A = 6249;
	TCCR1A = 0x00; //Seteo el timer1 en CTC mode
	TCCR1B = (1<<WGM12) | (1<<CS12); //CTC mode, preescalador en N=256
	TIMSK1 |= (1<<OCIE1A); //Activo interrupciones de registro OCR01	
}

void SEOS_Dispatch_Tasks(){
	
	if(FLAG_Sensor==1){ //Esto corre cada 500ms
		SYSTEM_Update(); //toma la temp y actualiza el sistema
		FLAG_Sensor=0;
	}
}

ISR(TIMER1_COMPA_vect){ //interrupción cada 100ms
	if(++iCont==5){
		FLAG_Sensor=1;	
		iCont=0;
	}
}

