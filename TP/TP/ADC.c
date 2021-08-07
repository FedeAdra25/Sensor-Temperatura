/*
 * ADC.c
 *
 * Created: 26-Jul-21 7:46:26 PM
 *  Author: fedea
 */ 

#include "ADC.h"

void ADC_Init(){
	//inicializa el ADC
	ADMUX=0x00; //Vref -> AREF = 5V , Right justified, pin ADC0
	ADCSRA = (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2); //Enable ADC w/ prescaler 128
	DIDR0 = (1<<ADC0D); //para que consuma menos el MCU deshabilitamos el Digital Input del puerto
}

uint16_t ADC_GetData(){
	//FUNCIÓN BLOQUEANTE
	//Convierte la entrada del pin ADC0 y la pasa al registro
	//retorna el valor del registro
	//con este valor, el sensortemp calcula el voltaje
	//y luego la temperatura
	
	ADCSRA |= (1<<ADSC); //Inicializo conversion
	while((ADCSRA & (1<<ADIF) == 0)); //se bloquea hasta que termina la conversión
	//to-do? timeout para evitar bloqueo?
	ADCSRA |= (1<<ADIF); //borra flag (debe borrarse si se usa polling)
	
	return ADC; //retorno el valor obtenido en mi ADC	
}