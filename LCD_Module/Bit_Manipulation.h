/*
 * Bit_Manipulation.h
 *
 * Created: 2015-12-01 2:44:49 AM
 *  Author: Ahmed Hisham
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

	typedef enum {INPUT,OUTPUT} dir;
	
	#define Set_Pin(port,pin)	do  {\
									port |= 1 << pin;\
								}	while(0);						
	#define Clear_Pin(port,pin) do	{\
									port &=~ (1 << pin);\
								}	while(0);
	#define Toggle_Pin(port,pin) do	{\
									port ^= (1 << pin);\
								}	while(0);					

#endif /* BIT_MANIPULATION_H_ */