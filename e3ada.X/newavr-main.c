/*
 * File:   main.c
 * Author: ahmed
 *
 * Created on January 22, 2022, 2:05 PM
 */


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define LED0   2
#define LED1   7
#define LED2   3
#define relay  2
#define buzzer  3
#define button0 0
#define button1 6
#define button2 2
void init_LEDs(void);
void LED_ON(int LED);
void LED_OFF(int LED);
void init_button(void);
void init_buzzer(void);
void buzzer_on(void);
void buzzer_off(void);
void init_relay(void);
void relay_on(void);
void relay_off(void);

int main(void) {
    /* Replace with your application code */
    init_LEDs();
    init_buzzer();
    init_relay();
    init_button();
    while (1) {
        LED_ON(LED1);
        _delay_ms(500);
        LED_OFF(LED1);
        _delay_ms(500);
        buzzer_on();
        _delay_ms(500);
        buzzer_off();
        _delay_ms(500);
        relay_on();
        _delay_ms(500);
        relay_off();
        _delay_ms(500);

    }
}

void init_LEDs(void) {
    DDRC |= (1 << LED0) | (1 << LED1);
    DDRD |= (1 << LED2);
}

void LED_ON(int LED) {
    if (LED == LED2) {
        PORTD |= (1 << LED);
    } else {
        PORTC |= (1 << LED);
    }

}

void LED_OFF(int LED) {
    if (LED == LED2) {
        PORTD &= ~(1 << LED);
    } else {
        PORTC &= ~(1 << LED);
    }
}

void init_button(void) {
    DDRD &= ~(1 << button1);
    DDRD &= ~(1 << button2);
    DDRB &= ~(1 << button0);
}

void init_buzzer(void) {
    DDRA |= (1 << buzzer);
}

void buzzer_on(void) {
    PORTA |= (1 << buzzer);
}

void buzzer_off(void) {
    PORTA &= ~(1 << buzzer);
}

void init_relay(void) {
    DDRA |= (1 << relay);
}

void relay_on(void) {
    PORTA |= (1 << relay);
}

void relay_off(void) {
    PORTA &= ~(1 << relay);
}
