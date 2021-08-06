/*
 * SensorTemp.c
 *
 * Created: 26-Jul-21 7:48:12 PM
 *  Author: fedea
 */ 



#include "SensorTemp.h"


tempType temperature;

void SENSORTEMP_Init(){
	temperature=24;
	ADC_Init();
}


tempType SENSORTEMP_MeasureTemp(){
	//toma el valor del registro del ADC
	//lo pasa a mV
	//calcula la Temperatura en °C
	//retorna el resultado en tempType
	
	uint16_t aux = ADC_GetData();
	
	
}