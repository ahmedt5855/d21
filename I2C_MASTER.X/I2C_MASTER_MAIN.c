/*
 * File:   I2C_MASTER_MAIN.c
 * Author: ahmed
 *
 * Created on March 15, 2022, 5:42 PM
 */

#define F_CPU           16000000UL 
#include <avr/io.h>
#include "I2C_MASTER.h"
int main(void) {
    /* Replace with your application code */
    init_TWI(OWN_ADDRESS);
    TWI_MT(SLA_W,9);
    while (1) {
    }
}
