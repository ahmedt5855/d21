/* 
 * File:   lcd_4bit.c
 * Author: ahmed
 *
 * Created on February 8, 2022, 4:58 PM
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

#include "lcd_4bit.h"

void init_lcd() {
    LCD_CONTROL_DIR |= (1 << RS) | (1 << RW) | (1 << EN);
    LCD_DATA_DIR |= 0xF0;
    LCD_CONTROL &= ~(1 << RW);
    _delay_ms(50);

    clear_lcd();
    lcd_cmd(0x02); /* Initialization of 16X2 LCD in 4bit mode */
    lcd_cmd(0x0C); /* Display ON Cursor OFF */
    lcd_cmd(0x06); /* Auto Increment cursor */
    _delay_ms(100);
}

void lcd_EN() {
    LCD_CONTROL |= (1 << EN);
    _delay_ms(5);
    LCD_CONTROL &= ~(1 << EN);
}

void clear_lcd() {
    lcd_cmd(0x01); /* clear display */
}

void lcd_write(char data) {
    LCD_CONTROL |= (1 << RS);
    LCD_DATA = (LCD_DATA & 0x0F) | (data & 0xF0);
    lcd_EN();

    LCD_DATA = (LCD_DATA & 0x0F) | (data << 4);

    lcd_EN();
}
    void lcd_cmd(char cmd) {

        LCD_CONTROL &= ~(1 << RS);
        LCD_DATA = (LCD_DATA & 0x0F) | (cmd & 0xF0);
        lcd_EN();
        LCD_DATA = (LCD_DATA & 0X0F) | (cmd << 4);
          lcd_EN();
    }

    void lcd_str(char *str) {
        int i;
        for (i = 0; str[i] != '\0'; i++) {
            lcd_write(str[i]);
        }
    }

    void lcd_num(int num) {
        char buffer[11];
        itoa(num, buffer, 10);
        lcd_str(buffer);
    }