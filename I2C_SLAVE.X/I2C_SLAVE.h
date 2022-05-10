/* 
 * File:   I2C_SLAVE.h
 * Author: ahmed
 *
 * Created on March 15, 2022, 8:23 PM
 */

#ifndef I2C_SLAVE_H
#define	I2C_SLAVE_H
#define SLA_W     0x06 // (0x03<<1)
#define SLA_R     0x07 //(0x03<<1)|1

#define OWN_Address  0x03
#define GeneralCall   0

#define STARTCONDITON  (1<<TWSTA)|(1<<TWINT)|(1<<TWEN) // 0xA4
#define STOPCONDITON   (1<<TWSTO)|(1<<TWINT)|(1<<TWEN) // 
#define ENABLEACK      (1<<TWEA)|(1<<TWINT)|(1<<TWEN) // 
#define SEND           (1<<TWINT)|(1<<TWEN) // 

void init_TWI(unsigned char address);
void TWI_operate(unsigned char command);
unsigned char TWI_checkStatus();
void TWI_load(unsigned char load);
char TWI_SR(void);
void TWI_ST(char data);
unsigned char st;

#endif	/* I2C_SLAVE_H */

