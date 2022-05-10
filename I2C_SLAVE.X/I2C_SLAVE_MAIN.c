/*
 * File:   I2C_SLAVE_MAIN.c
 * Author: ahmed
 *
 * Created on March 15, 2022, 8:24 PM
 */

#define F_CPU 16000000
#include <avr/io.h>
#include "I2C_SLAVE.h"
int main(void) {
    /* Replace with your application code */
    DDRA = 0XFF;
    init_TWI(OWN_Address);
    PORTA = TWI_SR();
    while (1) {
    }
}
