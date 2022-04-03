/* 
 * File:   M_ADC.c
 * Author: ahmed
 *
 * Created on February 11, 2022, 8:59 PM
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "M_ADC.h"
void select_ch(char ch)
{
    ADMUX &= 0xE0;
    ADMUX |= ch;
}
void select_vref(char vref)
{
    switch(vref){
        case AREF:
            ADMUX &= ~((1<<REFS1)|(1<<REFS0));
            break;
            
        case AVCC:
            ADMUX &= ~(1<<REFS1);
            ADMUX |= (1<<REFS0);
            break;
            
        case INTERNAL:
            ADMUX |= ((1<<REFS1)|(1<<REFS0));
            break;
            
    }
}
void select_pre(char pre)
{
    ADCSRA &= 0xF8; //11111000
    ADCSRA |= pre & 0x07; //0000111
}
void ADC_enable()
{
    ADCSRA |= (1<< ADEN);
}
void ADC_sc()
{
    ADCSRA |=(1<<ADSC);
}
void ADC_wait()
{
    while(!(ADCSRA & (1<<ADIF)));
    
}
int ADC_read()
{
    return ADCW ;
}
void ADC_int_enable()
{
    ADCSRA |=(1<<ADIE);
}
void ADC_int_disable()
{
    ADCSRA &=~(1<<ADIE);
}
void global_int()
{
    sei();
}
void init_ADC(char ch,char pre,char vref, char choose_booling)
{
    select_pre(pre);
    select_ch(ch);
    select_vref(vref);
    ADC_enable();
    if(choose_booling == 1)
    {
        ADC_int_disable();
    }
    else
    {
        ADC_int_enable();
        global_int();
    }
    
    
}
