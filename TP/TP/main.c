/*
 * TP.c
 *
 * Created: 26-Jul-21 6:10:29 PM
 * Author : fedeadra
 */ 


#include "main.h"


int main(void)
{
	LCDinit();
    SEOS_Init();
	VENTILADOR_Init();
	CALEFACTOR_Init();
	SENSORTEMP_Init();
	SYSTEM_Init();
	sei();
    while (1)
    {
		SEOS_Dispatch_Tasks();
    }
}

