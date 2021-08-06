/*
 * System.c
 *
 * Created: 06-Aug-21 4:36:13 PM
 *  Author: fedea
 */ 


#include "System.h"

tempType temperatura = 0;
static uint8_t * texto = "TEMP: 00.0°C";

void writeLCD(tempType temp);

void SYSTEM_Init(){
	
}

//Toma la temperatura del sensor y la actualiza en el LCD
//Prende y apaga el calefactor en caso de ser necesario
void SYSTEM_Update(){
	temperatura = SENSORTEMP_MeasureTemp();
	if(temperatura>MAX_T){
		VENTILADOR_TurnOn();
	}
	else{
		VENTILADOR_TurnOff();
	}
	if(temperatura<MIN_T){
		CALEFACTOR_TurnOn();
	}
	else{
		CALEFACTOR_TurnOff();
	}
	//ESCRIBIR EN EL LCD LA TEMPERATURA
	writeLCD(temperatura);		
}

void writeLCD(tempType temp){
	//texto -> "TEMP: xx.y °C"
	uint8_t temp = temp*10;
	texto[7] = (temp/100) % 10;
	texto[8] = (temp/10)  % 10;
	texto[10] = temp%10;
	LCDclr();
	LCDstring(texto);
}
