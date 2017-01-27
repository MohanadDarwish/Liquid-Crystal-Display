/*
 * LED.c
 *
 *  Author: Mohanad Darwish
 */ 
#include "Bit_Manipulation.h"
#include "DataTypes.h"
#include "LED.h"
#include "DIO_Interface.h"



void LED_Attach(ui8 port,ui8 pin)
{
	Set_Pin_Direction(port,pin,OUTPUT);
	Set_Pin_Value(port,pin,0);
}

void LED_On(ui8 port,ui8 pin)
{
	Set_Pin_Value(port,pin,1);
}

void LED_Off(ui8 port,ui8 pin)
{
	Set_Pin_Value(port,pin,0);
}

void LED_Toggle(ui8 port,ui8 pin,ui16 delay_toggle)
{
//	_delay_ms(delay_toggle);	
}
