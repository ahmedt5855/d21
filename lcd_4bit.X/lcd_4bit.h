/* 
 * File:   lcd_4bit.h
 * Author: ahmed
 *
 * Created on February 8, 2022, 4:54 PM
 */

#ifndef LCD_4BIT_H
#define	LCD_4BIT_H

#define	LCD_8BIT_H
#define LCD_DATA        PORTD
#define LCD_DATA_DIR    DDRD
#define LCD_CONTROL     PORTD
#define LCD_CONTROL_DIR     DDRD
#define RS  0
#define RW  1
#define EN  2


void init_lcd();
void lcd_cmd(char cmd);
void lcd_EN();
void clear_lcd();
void lcd_write(char data);
void lcd_str(char *str);
void lcd_num(int num);


#endif	/* LCD_4BIT_H */

