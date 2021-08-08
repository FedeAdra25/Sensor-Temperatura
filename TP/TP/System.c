/*
 * System.c
 *
 * Created: 06-Aug-21 4:36:13 PM
 *  Author: fedea
 */ 


#include "System.h"

static tempType temperatura = 0;
static char texto[14] = "TEMP: 00.0 [C]";
static unsigned char ventilador_on,calefactor_on;


static void writeLCD(tempType temp);

void SYSTEM_Init(){
	ventilador_on=0;
	calefactor_on=0;
	LCDclr();
}

//Toma la temperatura del sensor y la actualiza en el LCD
//Prende y apaga el calefactor en caso de ser necesario
void SYSTEM_Update(){
	temperatura = SENSORTEMP_MeasureTemp();
	if(temperatura>MAX_T){
		if(!ventilador_on){
			VENTILADOR_TurnOn();
			ventilador_on=1;
		}
	}
	else if(temperatura<MIN_T){
		if(!calefactor_on){
			CALEFACTOR_TurnOn();
			calefactor_on=1;
		}
	}
	else{
		if(calefactor_on){
			CALEFACTOR_TurnOff();
			calefactor_on=0;
		}	
		if(ventilador_on){
			VENTILADOR_TurnOff();
			ventilador_on=0;
		}
	}
	//ESCRIBIR EN EL LCD LA TEMPERATURA
	writeLCD(temperatura);		
}

static void writeLCD(tempType temp){
	//texto -> "TEMP: xx.y °C"
	temp = temp*10;
	texto[6] = '0' + ((unsigned short)temp/100) % 10;
	texto[7] = '0' + ((unsigned short)temp/10)  % 10;
	texto[9] = '0' + (unsigned short)temp       % 10;
	//texto[10] = '0' + (unsigned short)temp        %10;
	LCDGotoXY(0,0);
	LCDstring(texto,14);
}
