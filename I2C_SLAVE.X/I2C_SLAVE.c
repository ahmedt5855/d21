/* 
 * File:   I2C_SLAVE.c
 * Author: ahmed
 *
 * Created on March 15, 2022, 8:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "I2C_SLAVE.h"
void init_TWI(unsigned char address) {

    // Set Clock Freq
    // Set Prescalar >> TWPS >> TWSR
    TWSR &= ~((1 << TWPS1) | (1 << TWPS0));
    // Set TWBR value
    TWBR = 100;
    // Set my OWN address
    TWAR = (address << 1) | GeneralCall; // 0x01; // 00000001

}

void TWI_operate(unsigned char command) {
    TWCR = command;
}

unsigned char TWI_checkStatus() {

    // Waiting till Flag is raised so we can read the status value
    // and compare it with the corresponding table
    while (!(TWCR & (1 << TWINT)));

    return (TWSR & 0xF8);
}

void TWI_load(unsigned char load) {
    // Load either Address or Data 
    // Usually call SEND operation after it.
    TWDR = load;
    TWI_operate(SEND);
}
char  TWI_SR(void)
{
    TWI_operate(ENABLEACK);
    st = TWI_checkStatus();
    if(st=0x60)
    {
        TWI_operate(ENABLEACK);
        st = TWI_checkStatus();
        if(st = 0x80)
        {
            return TWDR;
        }
    }
}
void TWI_ST(char data)
{
    TWI_operate(ENABLEACK);
    st = TWI_checkStatus();
    if(0xA8)
    {
        TWDR = data;
        TWI_operate(SEND);
        st = TWI_checkStatus();
        if (st == 0xB8) {
            // Nothing to do unless there are more data to send.
        }
    }
}