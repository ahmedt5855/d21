/* 
 * File:   lcd_4bit.h
 * Author: ahmed
 *
 * Created on February 8, 2022, 4:54 PM
 */

#ifndef LCD_4BIT_H
#define	LCD_4BIT_H

#define	LCD_8BIT_H
#define LCD_DATA        PORTA
#define LCD_DATA_DIR    DDRA
#define LCD_CONTROL     PORTB
#define LCD_CONTROL_DIR     DDRB
#define RS  1
#define RW  2
#define EN  3


void init_lcd();
void lcd_cmd(char cmd);
void lcd_EN();
void clear_lcd();
void lcd_write(char data);
void lcd_str(char *str);
void lcd_num(int num);


#endif	/* LCD_4BIT_H */

