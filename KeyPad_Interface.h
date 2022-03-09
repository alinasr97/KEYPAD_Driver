/*
 * KeyPad_Interface.h
 *
 * Created: 01-Mar-22 1:45:07 PM
 *  Author: lenovo
 */ 
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "UTILS.h"
#include "DIO_Interface.h"

/******************** Pin Config ********************/
#define ROW0_PORT PORT_C
#define ROW0_PIN 0 
#define ROW1_PORT PORT_C
#define ROW1_PIN 1 
#define ROW2_PORT PORT_C
#define ROW2_PIN 2 
#define ROW3_PORT PORT_C
#define ROW3_PIN 3
 


#define COL0_PORT PORT_C
#define COL0_PIN 4
#define COL1_PORT PORT_C
#define COL1_PIN 5
#define COL2_PORT PORT_C
#define COL2_PIN 6
#define COL3_PORT PORT_C
#define COL3_PIN 7


/******************************************************/
void KEYPAD_Init(void);
u8 KEYPAD_GetEntry(void);

#endif /* KEYPAD_INTERFACE_H_ */
