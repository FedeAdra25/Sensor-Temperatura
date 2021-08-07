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
	
	unsigned long aux = ADC_GetData();
	temperature = aux * ADC_FACTOR; //consigo el voltaje de salida en mV
	//equivalente a hacer (aux*5000UL)/1024
	temperature = temperature/SENSORTEMP_FACTOR; //consigo el valor de la temperatura
	#if USING_FLOAT==1 //Como la resulución es de 0.5°C (aprox) fuerzo el incremento de temperatura a 0.5
	aux=temperature;
	temperature = ((temperature-aux>0.33) ? aux+0.5 : (temperature-aux>0.66) ? aux+1:aux);
	#endif
	return temperature;
}