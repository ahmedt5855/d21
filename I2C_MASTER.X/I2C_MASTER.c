/*
 * File:   I2C_MASTER.c
 * Author: ahmed
 *
 * Created on March 15, 2022, 5:43 PM
 */
#include <avr/io.h>
#include "I2C_MASTER.h"

void init_TWI(unsigned char address) {
    TWSR &= ~(1 << TWPS1) | (1 << TWPS0);
    TWBR = 255;
    TWAR |= (address << 1) | GeneralCall; // 0x01; // 00000001
}

unsigned char TWI_CHECK_STATUS() {
    while (!(TWCR & (1 << TWINT))); //WAIT UNTILL TWI FINISH HIS JOB
    return (TWSR & 0xF8); //TO EFFECT ON LAST FIVE BITS
}

void TWI_OPERATE(char command) {
    TWCR = command;
}

void TWI_LOAD(unsigned char data) {
    TWDR = data;
    TWI_OPERATE(SEND);
}

void TWI_MT(unsigned char address, char data) {
    TWI_OPERATE(START_CONDITION);
    st = TWI_CHECK_STATUS();
    if (st = 0x08) {
        TWI_LOAD(address);
        TWI_OPERATE(SEND);
        st = TWI_CHECK_STATUS();
        if (st = 0x18) {
            TWI_LOAD(data);
            TWI_OPERATE(SEND);
            st = TWI_CHECK_STATUS();
            if (st = 0x028) {
                TWI_OPERATE(STOP_CONDITION);
            }
        }
    }
}

char TWI_MR(unsigned char address) {
    TWI_OPERATE(START_CONDITION);
    st = TWI_CHECK_STATUS();
    if (st = 0x08) {
        TWI_LOAD(address);
        TWI_OPERATE(SEND);
        st = TWI_CHECK_STATUS();
        if (0x40) {
            TWI_OPERATE(ENACK);
            st = TWI_CHECK_STATUS();
            if (st = 0x50) {
                char data = TWDR;
                TWI_OPERATE(STOP_CONDITION);
                return data;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}