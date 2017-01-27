/*
 * DIO_Interface.h
 *
 *  Author: Mohanad Darwish
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
	#include <avr/io.h>
	#include "DataTypes.h"
	#include "Bit_Manipulation.h"
	
	void Set_Port_Direction (ui8 port,dir direction);
	void Set_Port_Value (ui8 port,ui8 value);
	ui8 Read_Port_Value (ui8 port);
	void Set_Pin_Direction (ui8 port,ui8 pin,dir direction);
	void Set_Pin_Value (ui8 port,ui8 pin,ui8 value);
	ui8 Read_Pin_Value (ui8 port,ui8 pin);
	void Set_Pin_Direction2 (ui8 pin,dir direction);
	void Set_Pin_Value2 (ui8 pin,ui8 value);
	ui8 Read_Pin_Value2 (ui8 pin);
	
#endif /* DIO_INTERFACE_H_ */