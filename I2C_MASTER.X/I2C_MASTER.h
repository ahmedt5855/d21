/* 
 * File:   I2C_MASTER.h
 * Author: ahmed
 *
 * Created on March 15, 2022, 5:42 PM
 */

#ifndef I2C_MASTER_H
#define	I2C_MASTER_H
#define START_CONDITION     (1<<TWSTA)|(1<<TWINT)|(1<<TWEN)
#define STOP_CONDITION      (1<<TWSTO)|(1<<TWINT)|(1<<TWEN)
#define ENACK               (1<<TWEA)|(1<<TWEN)|(1<<TWINT)
#define SEND                (1<<TWEN)|(1<<TWINT)
#define OWN_ADDRESS     0X07
#define SLA_W     0x06 // (0x03<<1)
#define SLA_R     0x07 //(0x03<<1)|1
#define GeneralCall   0
void init_TWI(unsigned char address);
unsigned char TWI_CHECK_STATUS();
void TWI_OPERATE(char command);
void TWI_LOAD(unsigned char data);
void TWI_MT(unsigned char address, char data);
char TWI_MR(unsigned char address);
char st;

#endif	/* I2C_MASTER_H */

