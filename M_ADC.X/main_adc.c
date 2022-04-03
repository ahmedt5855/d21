/*
 * File:   main_adc.c
 * Author: ahmed
 *
 * Created on February 11, 2022, 8:58 PM
 */

#define F_CPU 16000000
#include <avr/io.h>
#include "M_ADC.h"
#include "lcd_4bit.h"
#include <util/delay.h>

int main(void) {
    /* Replace with your application code */
    int data;
    init_lcd();
    init_ADC(CH0, pre_128, AVCC, BOOLING);
    while (1) {
        ADC_sc();
        ADC_wait();
        clear_lcd();
        data = ADC_read()*4.88281;
        lcd_num(data);
        _delay_ms(500);
    }
}
