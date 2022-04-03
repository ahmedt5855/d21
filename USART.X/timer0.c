/* 
 * File:   timer0.c
 * Author: ahmed
 *
 * Created on February 11, 2022, 10:59 PM
 */
#include <avr/io.h>
#include "timer0.h"
#include "M_ADC.h"

void select_clk(char clk) {
    TCCR0 &= 0xF8; //11111000
    TCCR0 |= clk;
}

void select_mode(char mode) {
    TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
    TCCR0 |= mode;
}

void select_operation(char op) {
    TCCR0 |= op;
}

void enable_int(char condition) {
    TIMSK &= 0xFB; //11111100 
    TIMSK |= condition & 0x03;
}

void disable_int(char condition) {
    TIMSK &= ~condition & 0x03;
}

void init_timer0(char clk, char mode, char condition) {

    select_mode(mode);
    enable_int(condition);
    select_clk(clk);
}

void timer0_compare_match(char val) {
    OCR0 = val;
}

void timer0_duty_cycle(char percentage) {
    OCR0 = percentage ;

}

void timer0_oc0_fpwm(char mode) {
    DDRB |= (1 << 3);
    TCCR0 |= (mode << COM00);
}

void timer0_oc0_pwm(char mode) {
    DDRB |= (1 << 3);
    TCCR0 |= (mode << COM00);
}