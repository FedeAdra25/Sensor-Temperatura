/*
 * SensorTemp.h
 *
 * Created: 26-Jul-21 7:48:21 PM
 *  Author: fedea
 */ 


#ifndef SENSORTEMP_H_
#define SENSORTEMP_H_

#include "ADC.h"

//Comentar y descomentar en función de como se quiera calcular la temp
#define tempType int
//#define tempType float

void SENSORTEMP_Init();

tempType SENSORTEMP_MeasureTemp();



#endif /* SENSORTEMP_H_ */