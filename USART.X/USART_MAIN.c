/*
 * File:   USART_MAIN.c
 * Author: ahmed
 *
 * Created on February 27, 2022, 4:34 PM
 */

#define F_CPU       16000000UL
#include <avr/io.h>
#include "USART.h"
#include "M_ADC.h"
#include "timer0.h"
#include <avr/interrupt.h>
#include <util/delay.h>

#define _LED0   0
#define MOTOR_pin   0
#define _LED1   1
char message1[] = "LED0 ON \r";
char message2[] = "LED0 OFF \r";
char message3[] = "LED1 ON \r";
char message4[] = "LED1 OFF \r";
char message5[] = "MOTOR ON \r";
char message6[] = "MOTOR OFF \r";

void setupLEDs() {
    DDRA |= (1 << _LED0) | (1 << _LED1);
}

void setupMOTOR() {
    DDRB |= (1 << MOTOR_pin);
}

void _LED_ON(int ledNum) {
    PORTA |= (1 << ledNum);
}

void _LED_OFF(int ledNum) {
    PORTA &= ~(1 << ledNum);
}

void motor_ON() {
    PORTB |= (1 << MOTOR_pin);
}

void motor_OFF() {
    PORTB &= ~(1 << MOTOR_pin);
}

ISR(USART_RXC_vect) {
    char receivedData = UDR;

    if (receivedData == 'A') {
        _LED_ON(_LED0);
        USART_SEND_STR(message1);
    }
    if (receivedData == 'B') {
        _LED_OFF(_LED0);
        USART_SEND_STR(message2);
    }
    if (receivedData == 'C') {
        _LED_ON(_LED1);
        USART_SEND_STR(message3);
    }
    if (receivedData == 'D') {
        _LED_OFF(_LED1);
        USART_SEND_STR(message4);
    }
}

ISR(TIMER0_OVF_vect) {
    static int count = 0;
    count++;

    if (count == 61 * 5) {
        count = 0;
        ADC_sc();
        ADC_wait();
        int data = ADC_read()* 4.8828125;
        if (data >= 3000) {
            motor_ON();
            USART_SEND_STR(message5);
        } else {
            motor_OFF();
            USART_SEND_STR(message6);
        }
        USART_SEND_NUM(data);
        USART_send('\r');
    }

}

int main(void) {
    /* Replace with your application code */
    setupMOTOR();
    setupLEDs();
    init_ADC(CH2, pre_128, AVCC, BOOLING);
    init_timer0(timer0_pre_1024, normal, over_flow);
    init_USART(9600);
    global_int();
    while (1) {
_delay_ms(2000);
    }
}
