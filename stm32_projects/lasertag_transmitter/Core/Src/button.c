/*
 * button.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Viacheslav
 */

#include "button.h"
uint8_t button()
{
	//static uint8_t last_value = 0;
	static uint8_t flag = 0;
	static uint8_t value = 0;
	static uint8_t start_tick = 0;
	uint8_t current_tick = 0;
	uint8_t current_value = 0;
	uint8_t time = 10; // in mS
	if(!flag)
			{
		start_tick = HAL_GetTick();
		flag = 1;
	}
	current_tick = HAL_GetTick();
	if(current_tick-start_tick >= time)
	{
	current_value = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	if(current_value == 1) value++;
	else value = 0;
	if(value >=10)
	{
		flag = 0;
		value = 0;
		return 1;

	}
	else return 0;
}}
