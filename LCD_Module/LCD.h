/*
 * LCD.h
 *
 *  Author: Mohanad Darwish
 */ 


#ifndef LCD_H_
#define LCD_H_
	#include <string.h>
	#include "DIO_Interface.h"
	#ifndef F_CPU
	#define F_CPU 8000000UL
	#endif
	//#define DATA_PORT_LENGHT 8
	#define DATA_PORT_LENGHT 4
	#if (DATA_PORT_LENGHT == 8)
		#define LCD_DATA_PORT 1
		#define LCD_DATA_DIRECTION 1
		#define LCD_CONTROL_PORT 0
		#define LCD_CONTROL_DIRECTION 0
	#endif
	#if (DATA_PORT_LENGHT == 4)
		#define LCD_DATA_PORT 0
		#define LCD_DATA_DIRECTION 0
		#define LCD_CONTROL_PORT 1
		#define LCD_CONTROL_DIRECTION 1
	#endif
	#define RS	1
	#define RW	2
	#define EN	3

	#include <util/delay.h>
	
	void LCD_INIT (void);
	void LCD_Send_CMD (ui8);
	void LCD_Display_char (ui8);
	void LCD_Move_Cursor (ui8,ui8);
	void LCD_Write_String (char *);
	void LCD_Clear_Screen (void);
	void LCD_Clear_Screen (void);
	void LCD_Display_Num(ui32);
#endif /* LCD_H_ */