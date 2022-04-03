/* 
 * File:   timer0.h
 * Author: ahmed
 *
 * Created on February 11, 2022, 10:58 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H
#define timer0_pre_stop                  0
#define timer0_pre_no                    1
#define timer0_pre_8                     2
#define timer0_pre_64                    3
#define timer0_pre_256                   4
#define timer0_pre_1024                  5
#define timer0_pre_EXTERNAL_FALLING      6
#define timer0_pre_EXTERNAL_RISING       7
#define normal                    0x00
#define PWM                       0x40
#define CTC                       0x08
#define fast_pwm                  0x48
#define compare_match             0x02
#define over_flow                 0x01
#define OC0_PWM_ClearUpSetDown   0x02
#define OC0_PWM_SetUpClearDown   0x03

#define OC0_FPWM_ClearSet  0x02
#define OC0_FPWM_SetClear  0x03
void timer0_compare_match(char val);
void select_mode(char mode);
void select_clk(char clk);
void select_operation(char op);
void enable_int(char condition);
void disable_int(char condition);
void timer0_duty_cycle(char percentage);
void init_timer0(char clk, char mode, char condition);
void timer0_oc0_pwm(char mode);
void timer0_oc0_fpwm(char mode);


#endif	/* TIMER0_H */

