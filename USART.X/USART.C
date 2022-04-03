/* 
 * File:   USART.C
 * Author: ahmed
 *
 * Created on February 27, 2022, 4:34 PM
 */
#define F_CPU       16000000UL
#include <stdio.h>
#include <avr/io.h>
#include <stdlib.h>
#include "USART.h"

void init_USART(int Baudrate) {
    //ENABLE RX,TX
    UCSRB |= (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
    short UBRR = (F_CPU / 16 / Baudrate) - 1;
    UBRRL = (char) UBRR;
    UBRRH = (char) (UBRR >> 8);
}

void USART_send(char data) {
    //booling till UDR is empty
    while (!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void USART_SEND_STR(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        USART_send(str[i]);

    }
}

void USART_SEND_NUM(int num) {
    char buff[11];
    itoa(num, buff, 10);
    USART_SEND_STR(buff);
}

char USART_read(void) {
    while (!(UCSRA & (1 << RXC)));
    char data = UDR;
    return data;
}


