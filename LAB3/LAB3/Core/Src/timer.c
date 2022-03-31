/*
 * timer.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Win10
 */
# include "main.h"
#include "input_reading.h"
#include "timer.h"

int timer0_counter;
int timer0_flag = 0;
int led_7_flag = 0;
int blink_flag=0;
void setTimer(int duration){
	timer0_counter = duration/10;
	timer0_flag = 0;
}

void timer_run(){
	if (timer0_counter > 0){
		timer0_counter--;
		button_reading();
		if (timer0_counter>50){
			led_7_flag = 1;
		}
		else {
			led_7_flag = 0;
		}
		if(timer0_counter%25==0){
			blink_flag=1;
		}
		else blink_flag=0;
		if (timer0_counter == 0) timer0_flag = 1;
	}
}
