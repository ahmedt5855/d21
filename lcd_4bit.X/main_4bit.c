/*
 * File:   main_4bit.c
 * Author: ahmed
 *
 * Created on February 8, 2022, 4:55 PM
 */


#include <avr/io.h>
#define F_CPU 16000000UL
#include "lcd_4bit.h"
#include <util/delay.h>


int main(void) {
    /* Replace with your application code */
    init_lcd();
    int x = 500;
    while (1) {
         init_lcd();
          lcd_num(x);
          _delay_ms(100);
    }
}
