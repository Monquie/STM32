/*
 * input_reading.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Win10
 */


# include "main.h"
# include "input_reading.h"

// we aim to work with more than one buttons
# define N0_OF_BUTTONS 3
// timer interrupt duration is 10ms , so to pass 1 second ,
// we need to jump to the interrupt service routine 100 time

# define DURATION_FOR_AUTO_INCREASING 100
# define BUTTON_IS_PRESSED GPIO_PIN_RESET
# define BUTTON_IS_RELEASED GPIO_PIN_SET

// the buffer that the final result is stored after
// debouncing

static GPIO_PinState buttonBuffer [ N0_OF_BUTTONS ];

// we define two buffers for debouncing

static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ];
static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ];
static uint16_t buttonPin[ N0_OF_BUTTONS]={BUTTON_0,BUTTON_1,BUTTON_2};

void reading_Init(void){
	for (int i=0; i < N0_OF_BUTTONS; i++){
		debounceButtonBuffer1[i]=BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i]=BUTTON_IS_RELEASED;
		buttonBuffer[i]=BUTTON_IS_RELEASED;
	}
}
static uint8_t counterInterval=0;
void button_reading ( void ){
	if (counterInterval>=7){
		counterInterval=0;
		for (unsigned int i = 0; i < N0_OF_BUTTONS ; i ++){
			debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin (GPIOB,buttonPin[i]);
			if( debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
				buttonBuffer [i] = debounceButtonBuffer1 [i];
			}
		}
	}
	else counterInterval++;
}


unsigned char is_button_pressed ( unsigned char index ){
	if( index >= N0_OF_BUTTONS ) return 0;
	if  ( buttonBuffer [index] == BUTTON_IS_PRESSED ){
		buttonBuffer[index]= BUTTON_IS_RELEASED;
		return 1;
	}
	else return 0;
}

