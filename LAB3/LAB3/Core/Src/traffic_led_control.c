/*
 * traffic_led_control.c
 *
 *  Created on: Oct 23, 2021
 *      Author: Win10
 */
#include "main.h"
#include "traffic_led_control.h"
#include "led_display.h"

#define N0_OF_LED 3

#define LED_ON 	GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET

static uint8_t bufferTimerForLED[N0_OF_LED];
static uint8_t counterRED,counterAMBER,counterGREEN;
static uint8_t timeRED,timeAMBER,timeGREEN;

uint8_t ERROR_HANDLING(uint8_t time){
	return (bufferTimerForLED[RED]-bufferTimerForLED[AMBER]==time)? time:bufferTimerForLED[RED]-bufferTimerForLED[AMBER];
}

void LED_TRAFFIC_STORE_BUFFER(uint8_t time, uint8_t index){
	bufferTimerForLED[index] = time;
}

void LED_TRAFFIC_LOAD_BUFFER(void){
	counterRED=bufferTimerForLED[RED];
	counterAMBER=bufferTimerForLED[AMBER];
	counterGREEN=bufferTimerForLED[GREEN];
	timeRED=bufferTimerForLED[RED];
	timeAMBER=bufferTimerForLED[AMBER];
	timeGREEN=bufferTimerForLED[GREEN];
}
void LED_TRAFFIC_INIT(void){
	HAL_GPIO_WritePin(PORT_RED1, PIN_RED1, LED_OFF);
	HAL_GPIO_WritePin(PORT_AMBER1, PIN_AMBER1, LED_OFF);
	HAL_GPIO_WritePin(PORT_GREEN1, PIN_GREEN1, LED_OFF);
	HAL_GPIO_WritePin(PORT_RED2, PIN_RED2, LED_OFF);
	HAL_GPIO_WritePin(PORT_AMBER2, PIN_AMBER2, LED_OFF);
	HAL_GPIO_WritePin(PORT_GREEN2, PIN_GREEN2, LED_OFF);

}
int counter=0;
void LED_TRAFFIC_RUN(void){
	counter++;
	if (counter <= timeGREEN){
		update_clock_buffer(counterRED, counterGREEN);
		HAL_GPIO_WritePin(PORT_RED2, PIN_RED2, LED_OFF);
		counterRED--;
		HAL_GPIO_WritePin(PORT_AMBER1, PIN_AMBER1, LED_OFF);
		HAL_GPIO_WritePin(PORT_RED1, PIN_RED1, LED_ON);
		HAL_GPIO_WritePin(PORT_GREEN2, PIN_GREEN2, LED_ON);
		counterGREEN--;

	} else if (counter <= timeGREEN+ timeAMBER){
		update_clock_buffer(counterRED, counterAMBER);
		HAL_GPIO_WritePin(PORT_GREEN2, PIN_GREEN2, LED_OFF);
		HAL_GPIO_WritePin(PORT_AMBER2, PIN_AMBER2, LED_ON);
		counterAMBER--;
		counterRED--;
	} else if (counter <= timeGREEN*2+ timeAMBER){
		update_clock_buffer(counterGREEN, counterRED);
		HAL_GPIO_WritePin(PORT_RED1, PIN_RED1, LED_OFF);
		HAL_GPIO_WritePin(PORT_GREEN1, PIN_GREEN1, LED_ON);
		counterGREEN--;
		HAL_GPIO_WritePin(PORT_AMBER2, PIN_AMBER2, LED_OFF);
		HAL_GPIO_WritePin(PORT_RED2, PIN_RED2, LED_ON);
		counterRED--;
	} else if (counter <= timeGREEN*2+ timeAMBER*2){
		update_clock_buffer(counterAMBER, counterRED);
		HAL_GPIO_WritePin(PORT_GREEN1, PIN_GREEN1, LED_OFF);
		HAL_GPIO_WritePin(PORT_AMBER1, PIN_AMBER1, LED_ON);
		counterAMBER--;
		counterRED--;
	}
	if (counter == timeGREEN){
		counterGREEN=bufferTimerForLED[GREEN];
	} else if (counter == timeGREEN+timeAMBER){
		counterRED=bufferTimerForLED[RED];
		counterAMBER=bufferTimerForLED[AMBER];
	} else if (counter == timeGREEN*2+ timeAMBER){
		counterGREEN=bufferTimerForLED[GREEN];
	} else if (counter == timeGREEN*2+ timeAMBER*2){
		counterRED=bufferTimerForLED[RED];
		counterAMBER=bufferTimerForLED[AMBER];
	}
	if(counter >= timeGREEN*2+timeAMBER*2) {
		counter=0;
	}
}

