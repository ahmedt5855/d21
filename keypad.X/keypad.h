/* 
 * File:   keypad.h
 * Author: ahmed
 *
 * Created on February 3, 2022, 2:44 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H
#define Keypad_DIR       DDRD
#define Keypad_DATA_OUT  PORTD
#define Keypad_DATA_IN   PIND

#define column0       4
#define column1       5
#define column2       6
#define column3       7
void init_KeyPad();
int getKeypad();
#endif	/* KEYPAD_H */

