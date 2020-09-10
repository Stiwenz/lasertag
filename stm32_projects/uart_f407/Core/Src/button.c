/*
 * button.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Viacheslav
 */

#include "button.h"
static uint8_t value;
uint8_t true_result;

uint8_t n;
extern uint8_t BUFF[9];
uint8_t time;
uint8_t pause;
uint8_t current_time;
uint8_t hold;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;


uint8_t button(TIM_HandleTypeDef *htim, GPIO_TypeDef * port, uint16_t pin ){
uint8_t current_value = 0;

	if (htim->Instance == TIM1) //check if the interrupt comes from TIM15
	{
		current_value = HAL_GPIO_ReadPin(port, pin);
		if (current_value == 1)
			value++;
		else {
			value = 0;
			true_result = 0;
		}
		if (value >= 30) {
			true_result = 1;

		}
		return true_result;

	}
}
