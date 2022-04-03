/* 
 * File:   USART.h
 * Author: ahmed
 *
 * Created on February 27, 2022, 4:33 PM
 */

#ifndef USART_H
#define	USART_H

void init_USART(int Baudrate);
void USART_send(char data);
char USART_read(void);
void USART_SEND_NUM(int num);
void USART_SEND_STR(char str[]);



#endif	/* USART_H */

