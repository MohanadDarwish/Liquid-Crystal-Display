/*
 * LED.h
 *
 *  Author: Mohanad Darwish
 */ 


#ifndef LED_H_
#define LED_H_
	#define F_CPU 8000000UL
	#include "DataTypes.h"
	#include <util/delay.h>
	void LED_Attach(ui8,ui8);
	void LED_On(ui8,ui8);
	void LED_Off(ui8,ui8);
	void LED_Toggle(ui8,ui8,ui16);
#endif /* LED_H_ */