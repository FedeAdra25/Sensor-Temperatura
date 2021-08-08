/*
 * SensorTemp.c
 *
 * Created: 26-Jul-21 7:48:12 PM
 *  Author: fedea
 */ 



#include "SensorTemp.h"




void SENSORTEMP_Init(){
	ADC_Init();
}


tempType SENSORTEMP_MeasureTemp(){
	//toma el valor del registro del ADC
	//lo pasa a mV
	//calcula la Temperatura en °C
	//retorna el resultado en tempType
	tempType temperature;
	
	unsigned long aux = ADC_GetData();
	temperature = (tempType)aux * ADC_FACTOR; //consigo el voltaje de salida en mV
	//equivalente a hacer (aux*5000UL)/1024
	temperature = temperature/SENSORTEMP_FACTOR; //consigo el valor de la temperatura
	
	
	//Como la resulución es de 0.5°C (aprox) fuerzo el incremento de temperatura a 0.5
	//((solo si trabajo con floats))
	
	#ifdef USING_FLOAT
		aux=temperature;
		temperature = ((temperature-aux>0.33 && temperature-aux<0.66) ? aux+0.5 : (temperature-aux>0.66) ? aux+1:aux);
	#endif
	
	return temperature;
}