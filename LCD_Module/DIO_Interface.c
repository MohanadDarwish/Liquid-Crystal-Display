/*
 * DIO_Interface.c
 *
 *  Author: Mohanad Darwish
 */ 

#include "DIO_Interface.h"
volatile ui8* temp = &DDRA;
void which_port (ui8 port,ui8 d)
{
	if (d==0)
	{
		switch (port)
		{
			case 0:
			temp = &DDRA;
			break;
			case 1:
			temp = &DDRB;
			break;
			case 2:
			temp = &DDRC;
			break;
			case 3:
			temp = &DDRD;
			break;
		}	
	}
	else if (d==1)
	{
		switch (port)
		{
			case 0:
			temp = &PORTA;
			break;
			case 1:
			temp = &PORTB;
			break;
			case 2:
			temp = &PORTC;
			break;
			case 3:
			temp = &PORTD;
			break;
		}
	}	
	else{}
}
void which_port2 (ui8 pin,ui8 d)
{
	if (d==0)
	{
		if (pin >=0 && pin <=7)
			temp = &DDRA;
		else if (pin >=8 && pin <=15)
			temp = &DDRB;
		else if (pin >=16 && pin <=23)
			temp = &DDRC;
		else if (pin >24 && pin <=32)
			temp = &DDRD;
	}
	else if (d==1)
	{
		if (pin >=0 && pin <=7)
		temp = &PORTA;
		else if (pin >=8 && pin <=15)
		temp = &PORTB;
		else if (pin >=16 && pin <=23)
		temp = &PORTC;
		else if (pin >24 && pin <=32)
		temp = &PORTD;
	}
	else{}
}

void Set_Port_Direction (ui8 port,dir direction)
{
	which_port(port,0);
	if (direction==OUTPUT)
		*temp = 0xFF;
	else
		*temp = 0x00;
}
void Set_Port_Value (ui8 port,ui8 value)
{
	which_port(port,1);
	*temp=value;
}
ui8 Read_Port_Value (ui8 port)
{
	which_port(port,1);
	return *temp;
}
void Set_Pin_Direction (ui8 port,ui8 pin,dir direction)
{
	which_port(port,0);
	if (direction == INPUT)
	{
		Clear_Pin(*temp,pin);
	}
	else
	{
		Set_Pin(*temp,pin);
	}
}
void Set_Pin_Value (ui8 port,ui8 pin,ui8 value)
{
	which_port(port,1);
	if (value==0)
	{
		Clear_Pin(*temp,pin);	
	}
	else if (value == 1)
	{
		Set_Pin(*temp,pin);
	}
	else {}
}
ui8 Read_Pin_Value (ui8 port,ui8 pin)
{
	which_port(port,1);
	ui8 tempp = *temp;
	tempp &= (1<<pin);
	if (tempp>0)
		return 1;
	else
		return 0;
}
void Set_Pin_Direction2 (ui8 pin,dir direction)
{
	which_port2(pin,0);
	pin = pin % 8;
	if (direction == INPUT)
{
		Clear_Pin(*temp,pin);
}
	else
{
		Set_Pin(*temp,pin);
}
}
void Set_Pin_Value2 (ui8 pin,ui8 value)
{
	which_port2(pin,1);
	pin = pin % 8;
	if (value==0)
	{
		Clear_Pin(*temp,pin);
	}
	else if (value == 1)
	{
		Set_Pin(*temp,pin);
	}
	else {}
}
ui8 Read_Pin_Value2 (ui8 pin)
{
	which_port2(pin,1);
	pin = pin % 8;
	ui8 tempp = *temp;
	tempp &= (1<<pin);
	if (tempp>0)
	return 1;
	else
	return 0;
}