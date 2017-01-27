/*
 * LCD  main.c
 *
 * Author : Mohanad Darwish
 */ 

#include <avr/io.h>
#include "LCD.h"

int main(void)
{
	LCD_INIT();
	LCD_Write_String("Name is : ");
	LCD_Move_Cursor(1,2);
	LCD_Write_String("Mohanad Darwish");
	//LCD_Display_Num(22235);
    while (1) 
    {
		
    }
}

