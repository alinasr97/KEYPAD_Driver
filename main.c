#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "UTILS.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "HB_Interface.h"
#include "UART_Interface.h"
#include "LCD_Interface.h"
#include "PWM_Interface.h"
#include "Servo_Interface.h"
#include "KeyPad_Interface.h"

int main(void)
{
	KEYPAD_Init();
	LCD_Init();
	u8 KeyPressed=0,flag=0;
	while (1)
	{	
		do 
		{ KeyPressed=KEYPAD_GetEntry();
			_delay_ms(20);
			//KeyPressed=KEYPAD_GetEntry();
		} while (KeyPressed==0);
		if(KeyPressed=='#')
		{
			LCD_Clear();
		}
		else{
			if((KeyPressed>='*')&&KeyPressed<='=')
			{
				LCD_WriteChar(KeyPressed);
			}
		}
	}
}
