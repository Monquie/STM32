/*
 * input_reading.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Win10
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_


void button_reading ( void );
unsigned char is_button_pressed ( unsigned char index );
unsigned char is_button_pressed_1s ( unsigned char index );
void reading_Init(void);
#endif /* INC_INPUT_READING_H_ */
