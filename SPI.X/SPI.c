/* 
 * File:   SPI.c
 * Author: ahmed
 *
 * Created on March 1, 2022, 3:18 PM
 */
#define F_CPU           16000000
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"

void spi_clk(char clk) {
    SPCR |= clk;
}

void spi_mode() {
    SPCR = (1 << MSTR);
}

void spi_enable() {
    SPCR = (1 << SPE);
}

void init_spi(char clk) {
    DDRB |= (1 << MOSI) | (1 << SS) | (1 << SCK);
    spi_clk(clk);
    spi_mode();
    spi_enable();

}

void SPI_send(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));

}

void SPI_SEND_STR(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        SPI_send(str[i]);

    }
}

void SPI_SEND_NUM(int num) {
    char buff[11];
    itoa(num, buff, 10);
    SPI_SEND_STR(buff);
}