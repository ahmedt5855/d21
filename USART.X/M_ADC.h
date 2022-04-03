/* 
 * File:   M_ADC.h
 * Author: ahmed
 *
 * Created on February 11, 2022, 8:58 PM
 */

#ifndef M_ADC_H
#define	M_ADC_H
#define CH0     0
#define CH1     1
#define CH2     2
#define CH3     3
#define CH4     4
#define CH5     5
#define CH6     6
#define CH7     7
#define AREF        0
#define AVCC        1
#define INTERNAL    3
#define pre_2       1
#define pre_4       2
#define pre_8       3
#define pre_16      4
#define pre_32      5
#define pre_64      6
#define pre_128     7
#define BOOLING     1
#define NON_BOOLING 0
//ADMUX
void select_ch(char ch);
void select_vref(char vref);
//ADCSRA
void select_pre(char pre);
void ADC_enable();
void ADC_sc ();
void ADC_wait();
int ADC_read();
void ADC_int_enable();
void ADC_int_disable();
void global_int();
void init_ADC(char ch,char pre,char vref, char choose_booling);


#endif	/* M_ADC_H */

