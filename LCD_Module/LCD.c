/*
 * LCD.c
 *
 * Created: 2015-12-03 7:44:06 PM
 *  Author: Ahmed Hisham
 */
#include "LCD.h"

void LCD_INIT (void)
{
	Set_Pin_Direction(LCD_CONTROL_DIRECTION,RS,OUTPUT);
	Set_Pin_Direction(LCD_CONTROL_DIRECTION,RW,OUTPUT);
	Set_Pin_Direction(LCD_CONTROL_DIRECTION,EN,OUTPUT);
	Set_Pin_Value(LCD_CONTROL_PORT,RS,0);
	Set_Pin_Value(LCD_CONTROL_PORT,RW,0);
	Set_Pin_Value(LCD_CONTROL_PORT,EN,0);
	Set_Port_Direction(LCD_DATA_DIRECTION,OUTPUT);
	Set_Port_Value(LCD_DATA_PORT,0x00);
	#if (DATA_PORT_LENGHT == 8)
	LCD_Send_CMD(0x38);
	#endif
	#if (DATA_PORT_LENGHT == 4)
	LCD_Send_CMD(0x33);
	LCD_Send_CMD(0x32);
	LCD_Send_CMD(0x28);
	#endif
	LCD_Send_CMD(0x0E);
	LCD_Send_CMD(0x01);
	LCD_Send_CMD(0x06);
	return;
}
void LCD_Send_CMD (unsigned char cmd)
{
	Set_Pin_Value(LCD_CONTROL_PORT,RS,0);
	Set_Pin_Value(LCD_CONTROL_PORT,RW,0);
	Set_Port_Value(LCD_DATA_PORT,((Read_Port_Value(LCD_DATA_PORT) & 0x0f) | (cmd & 0xf0)));
	Set_Pin_Value(LCD_CONTROL_PORT,EN,1);
	_delay_us(1);
	Set_Pin_Value(LCD_CONTROL_PORT,EN,0);
	if( (cmd == 0x01) | (cmd == 0x02) )
	{
		_delay_ms(2);
	}
	else
	{
		_delay_us(100);
	}
	Set_Port_Value(LCD_DATA_PORT,((Read_Port_Value(LCD_DATA_PORT) & 0x0f) | (cmd<<4)));
	Set_Pin_Value(LCD_CONTROL_PORT,EN,1);
	_delay_us(1);
	Set_Pin_Value(LCD_CONTROL_PORT,EN,0);
	if( (cmd == 0x01) | (cmd == 0x02) )
	{
		_delay_ms(2);
	}
	else
	{
		_delay_us(100);
	}
	return;
}
void LCD_Display_char (unsigned char chr)
{
	Set_Pin_Value(LCD_CONTROL_PORT,RS,1);
	Set_Pin_Value(LCD_CONTROL_PORT,RW,0);
	Set_Port_Value(LCD_DATA_PORT,((Read_Port_Value(LCD_DATA_PORT) & 0x0f) | (chr & 0xf0)));
	Set_Pin_Value(LCD_CONTROL_PORT,EN,1);
	_delay_us(1);
	Set_Pin_Value(LCD_CONTROL_PORT,EN,0);
	_delay_us(100);
	Set_Port_Value(LCD_DATA_PORT,((Read_Port_Value(LCD_DATA_PORT) & 0x0f) | (chr<<4)));
	Set_Pin_Value(LCD_CONTROL_PORT,EN,1);
	_delay_us(1);
	Set_Pin_Value(LCD_CONTROL_PORT,EN,0);
	_delay_us(100);
	return;
}
void LCD_Move_Cursor (unsigned char xpos,unsigned char ypos)
{
	if (ypos==1)
	{
		LCD_Send_CMD(0x80+xpos-1);
	}
	else
	{
		LCD_Send_CMD(0xC0+xpos-1);
	}
}
void LCD_Write_String (char * str)
{
	int i =0;
	for (;i<strlen(str);i++)
	{
		LCD_Display_char(str[i]);
	}
}
void LCD_Clear_Screen (void)
{
	LCD_Send_CMD(0x01);
}
void LCD_Display_Num(ui32 Num)
{
	ui8 arr[10];
	ui32 temp = Num;
	int i=0;
	while (temp != 0)
	{
		ui8 rm_tmp = temp%10;
		temp /=10;
		arr[i]=rm_tmp+48;
		i++;
	}
	i--;
	for (;i>=0;i--)
	{
		LCD_Display_char(arr[i]);
	}
}