/*
 * input_processing.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Win10
 */

#include "main.h"
#include "input_reading.h"
#include "timer.h"
#include "traffic_led_control.h"
#include "led_display.h"

enum ButtonState { MODE_1 , MODE_2 , MODE_3 , MODE_4 } ;

enum ButtonState buttonState = MODE_1;

static uint8_t counterMode2,counterMode3,counterMode4;
void fsm_for_input_processing ( void ){
	switch (buttonState){
	case MODE_1:
		update_seven_segment_driver(led_7_flag);
		if (is_button_pressed(0)){
			buttonState = MODE_2;
			counterMode2=0;
			LED_TRAFFIC_INIT();
			setTimer(1000);
		}
		if (timer0_flag==1){
			LED_TRAFFIC_RUN();
			setTimer(1000);
		}
		break;
	case MODE_2:
		update_clock_buffer(counterMode2, 2);
		update_seven_segment_driver(led_7_flag);
		if (is_button_pressed(0)){
			buttonState = MODE_3;
			counterMode3=0;
			setTimer(1000);
			LED_TRAFFIC_INIT();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
		}
		if (blink_flag){
			HAL_GPIO_TogglePin(PORT_RED1, PIN_RED1);
		}
		if (is_button_pressed(1)){
			counterMode2=(counterMode2+1)%99;
		}
		if (is_button_pressed(2)){
			LED_TRAFFIC_STORE_BUFFER(counterMode2, RED);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
		}
		if (timer0_flag==1){
			setTimer(1000);
		}
		break;
	case MODE_3:
		update_clock_buffer(counterMode3, 3);
		update_seven_segment_driver(led_7_flag);
		if (is_button_pressed(0)){
			buttonState = MODE_4;
			counterMode4=0;
			setTimer(1000);
			LED_TRAFFIC_INIT();
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
		}
		if (blink_flag){
			HAL_GPIO_TogglePin(PORT_AMBER1, PIN_AMBER1);
		}
		if (is_button_pressed(1)){
			counterMode3=(counterMode3+1)%99;
		}
		if (is_button_pressed(2)){
			LED_TRAFFIC_STORE_BUFFER(counterMode3, AMBER);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
		}
		if (timer0_flag==1){
			setTimer(1000);
		}
		break;
	case MODE_4:
		update_clock_buffer(counterMode4, 4);
		update_seven_segment_driver(led_7_flag);
		if (is_button_pressed(0)){
			buttonState = MODE_1;
			counterMode2=0;
			setTimer(1000);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
			LED_TRAFFIC_STORE_BUFFER(ERROR_HANDLING(counterMode4), GREEN);
			LED_TRAFFIC_INIT();
			LED_TRAFFIC_LOAD_BUFFER();
		}
		if (blink_flag){
			HAL_GPIO_TogglePin(PORT_GREEN1, PIN_GREEN1);
		}
		if (is_button_pressed(1)){
			counterMode4=(counterMode4+1)%99;
		}
		if (is_button_pressed(2)){
			LED_TRAFFIC_STORE_BUFFER(ERROR_HANDLING(counterMode4), GREEN);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 1);
		}
		if (timer0_flag==1){
			setTimer(1000);
		}
		break;
	default:
		buttonState = MODE_1;
	}

}
