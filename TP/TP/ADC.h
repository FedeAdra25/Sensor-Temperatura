/*
 * ADC.h
 *
 * Created: 26-Jul-21 7:46:35 PM
 *  Author: fedea
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

#define VREF 5000UL //5000mV para Vref
#define ADC_FACTOR VREF/1024 //Factor de conversión [mV]

void ADC_Init();
uint16_t ADC_GetData();


#endif /* ADC_H_ */