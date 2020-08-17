/*
 * readit.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Slavon
 */

#include <LASERWAR.h>

// variables
uint8_t n;
uint8_t hex;
uint8_t time;
uint8_t pause;
uint8_t current_time;
uint8_t BUFF[9];
/////////

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

void readbit(uint8_t hex) {
	extern bit_number;
	BUFF[0] = HEADER;
	for (uint8_t i = 0; i < bit_number; i++) {

		if (BitIsSet(hex,(bit_number-1-i)) == 1)

		{

			BUFF[i + 1] = HIGH;

		} else

		{

			BUFF[i + 1] = LOW;

		}
	}
}

void send_hex(uint8_t hex, uint8_t bit_number) {
	readbit(hex);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&htim1);
	time = BUFF[0];
	pause = 1;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == TIM1) //check if the interrupt comes from TIM15
	{

		current_time++;
		if (current_time == time) {
			if (pause) {
				HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
				time = TIME_STOP;
				pause = 0;
				current_time = 0;


			}

			else {
				n++;
				if (n == 9) {
					HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
					n = 0;
					HAL_TIM_Base_Stop_IT(&htim1);
				} else
					HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
				time = BUFF[n];
				pause = 1;
				current_time = 0;

			}
		}

	}
}
