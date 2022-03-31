/*
 * timer.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Win10
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#define TIMER_CYCLE 10;

extern int timer0_flag;
extern int led_7_flag ;
extern int blink_flag;
void setTimer(int duration);
void timer_run();

#endif /* INC_TIMER_H_ */
