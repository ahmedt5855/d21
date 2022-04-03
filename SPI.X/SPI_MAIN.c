/*
 * File:   SPI_MAIN.c
 * Author: ahmed
 *
 * Created on March 1, 2022, 3:17 PM
 */

#define F_CPU           16000000UL
#include <avr/io.h>
#include "SPI.h"
#include <util/delay.h>
int num = 15;
char name = 'A';

int main(void) {
    /* Replace with your application code */
    init_spi(_spi_pre_128);
    while (1) {
        SPI_send('A');
        _delay_ms(2);
    }
}
