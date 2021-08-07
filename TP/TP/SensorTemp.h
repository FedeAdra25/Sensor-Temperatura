/*
 * SensorTemp.h
 *
 * Created: 26-Jul-21 7:48:21 PM
 *  Author: fedea
 */ 


#ifndef SENSORTEMP_H_
#define SENSORTEMP_H_

#include "ADC.h"

#define SENSORTEMP_FACTOR 10 //Factor de conversión [°C]


//Comentar y descomentar en función de si se quiere calcular
//temp con flotante o con enteros
#define USING_FLOAT 0
#ifdef USING_FLOAT
typedef float tempType;
#else
typedef unsigned short tempType;
#endif

void SENSORTEMP_Init();

tempType SENSORTEMP_MeasureTemp();



#endif /* SENSORTEMP_H_ */