/*
 * File:   newavr-main.c
 * Author: ahmed
 *
 * Created on February 3, 2022, 2:42 PM
 */


#include <avr/io.h>
#include "keypad.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void) {

    DDRA = 0xFF;
    init_KeyPad();

    while (1) {

        PORTA = getKeypad();

    }

}