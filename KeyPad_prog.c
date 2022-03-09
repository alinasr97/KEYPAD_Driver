/*
 * KeyPad_prog.c
 *
 * Created: 01-Mar-22 1:44:49 PM
 *  Author: lenovo
 */ 

#include "KeyPad_Interface.h"


void KEYPAD_Init(void)
{
	DIO_SetPinDirection(ROW0_PORT,ROW0_PIN,OUTPUT);
	DIO_SetPinDirection(ROW1_PORT,ROW1_PIN,OUTPUT);
	DIO_SetPinDirection(ROW2_PORT,ROW2_PIN,OUTPUT);
	DIO_SetPinDirection(ROW3_PORT,ROW3_PIN,OUTPUT);
	
	DIO_SetPinDirection(COL0_PORT,COL0_PIN,INPUT);
	DIO_SetPinValue(COL0_PORT,COL0_PIN,HIGH);
	DIO_SetPinDirection(COL1_PORT,COL1_PIN,INPUT);
	DIO_SetPinValue(COL1_PORT,COL1_PIN,HIGH);
	DIO_SetPinDirection(COL2_PORT,COL2_PIN,INPUT);
	DIO_SetPinValue(COL2_PORT,COL2_PIN,HIGH);
	DIO_SetPinDirection(COL3_PORT,COL3_PIN,INPUT);
	DIO_SetPinValue(COL3_PORT,COL3_PIN,HIGH);
}



u8 KEYPAD_GetEntry(void)
{
	u8 x=0;
	DIO_SetPinValue(ROW0_PORT,ROW0_PIN,LOW);
	DIO_SetPinValue(ROW1_PORT,ROW1_PIN,HIGH);
	DIO_SetPinValue(ROW2_PORT,ROW2_PIN,HIGH);
	DIO_SetPinValue(ROW3_PORT,ROW3_PIN,HIGH);
	
	x |=(DIO_GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x |=(DIO_GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x |=(DIO_GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x |=(DIO_GetPinValue(COL3_PORT,COL3_PIN)<<3);
	
	switch(x)
	{
		case 0x07:
			return '/'; break;
		case 0x0B:
			return '9'; break;
		case 0x0D:
			return '8'; break;
		case 0x0E:
			return '7';	 break;	
	}
	
	x=0;
	DIO_SetPinValue(ROW0_PORT,ROW0_PIN,HIGH);
	DIO_SetPinValue(ROW1_PORT,ROW1_PIN,LOW);
	DIO_SetPinValue(ROW2_PORT,ROW2_PIN,HIGH);
	DIO_SetPinValue(ROW3_PORT,ROW3_PIN,HIGH);
	
	x |=(DIO_GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x |=(DIO_GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x |=(DIO_GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x |=(DIO_GetPinValue(COL3_PORT,COL3_PIN)<<3);
	
	switch(x)
	{
		case 0x07:
			return '*'; break;
		case 0x0B:
			return '6'; break;
		case 0x0D:
			return '5'; break;
		case 0x0E:
			return '4'; break;
	}
	
	x=0;
	DIO_SetPinValue(ROW0_PORT,ROW0_PIN,HIGH);
	DIO_SetPinValue(ROW1_PORT,ROW1_PIN,HIGH);
	DIO_SetPinValue(ROW2_PORT,ROW2_PIN,LOW);
	DIO_SetPinValue(ROW3_PORT,ROW3_PIN,HIGH);
	
	x |=(DIO_GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x |=(DIO_GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x |=(DIO_GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x |=(DIO_GetPinValue(COL3_PORT,COL3_PIN)<<3);
	
	switch(x)
	{
		case 0x07:
			return '-'; break;
		case 0x0B:
			return '3'; break;
		case 0x0D:
			return '2'; break;
		case 0x0E:
			return '1'; break;
	}
	
	 x=0;
	DIO_SetPinValue(ROW0_PORT,ROW0_PIN,HIGH);
	DIO_SetPinValue(ROW1_PORT,ROW1_PIN,HIGH);
	DIO_SetPinValue(ROW2_PORT,ROW2_PIN,HIGH);
	DIO_SetPinValue(ROW3_PORT,ROW3_PIN,LOW);
	
	x |=(DIO_GetPinValue(COL0_PORT,COL0_PIN)<<0);
	x |=(DIO_GetPinValue(COL1_PORT,COL1_PIN)<<1);
	x |=(DIO_GetPinValue(COL2_PORT,COL2_PIN)<<2);
	x |=(DIO_GetPinValue(COL3_PORT,COL3_PIN)<<3);
	
	switch(x)
	{
		case 0x07:
			return '+'; break;
		case 0x0B:
			return '='; break;
		case 0x0D:
			return '0'; break;
		case 0x0E:
			return '#'; break;
	}
	return 0xFF;
}
