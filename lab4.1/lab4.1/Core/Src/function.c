#include "function.h"

#include "main.h"
void runLed1(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
}
void runLed2(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
}
void runLed3(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}
void runLed4(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
}
void runLed5(){
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
