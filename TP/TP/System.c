/*
 * System.c
 *
 * Created: 06-Aug-21 4:36:13 PM
 *  Author: fedea
 */ 


#include "System.h"

tempType temperatura = 0;
static char texto[14] = "TEMP: 00.0 [C]";

static void writeLCD(tempType temp);

void SYSTEM_Init(){
	LCDclr();
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

static void writeLCD(tempType temp){
	//texto -> "TEMP: xx.y °C"
	temp = temp*10;
	texto[6] = '0' + ((unsigned short)temp/100) % 10;
	texto[7] = '0' + ((unsigned short)temp/10)  % 10;
	texto[9] = '0' + (unsigned short)temp%10;
	LCDGotoXY(0,0);
	LCDstring(texto,14);
}
