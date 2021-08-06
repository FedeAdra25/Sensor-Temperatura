/*
 * System.h
 *
 * Created: 06-Aug-21 4:37:15 PM
 *  Author: fedea
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

#define MAX_T 24
#define MIN_T 17

#include "SensorTemp.h"
#include "Ventilador.h"
#include "Calefactor.h"
#include "LCD.h"



void SYSTEM_Init();

void SYSTEM_Update();


#endif /* SYSTEM_H_ */