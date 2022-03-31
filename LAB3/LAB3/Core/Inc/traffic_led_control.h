/*
 * traffic_led_control.h
 *
 *  Created on: Oct 23, 2021
 *      Author: Win10
 */

#ifndef INC_TRAFFIC_LED_CONTROL_H_
#define INC_TRAFFIC_LED_CONTROL_H_

void LED_TRAFFIC_STORE_BUFFER(uint8_t time, uint8_t index);
void LED_TRAFFIC_LOAD_BUFFER(void);
void LED_TRAFFIC_RUN(void);
void LED_TRAFFIC_INIT(void);
uint8_t ERROR_HANDLING(uint8_t time);
#endif /* INC_TRAFFIC_LED_CONTROL_H_ */
