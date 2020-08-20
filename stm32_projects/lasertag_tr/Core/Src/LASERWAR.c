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
uint8_t BUFF[32];
//Laser *_str;

/////////

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

void readbit(uint8_t hex, Laser *_str) {
	BUFF[0] = HEADER;
	for (uint8_t i = 0; i < _str->bits_number; i++) {

		if (BitIsSet(hex,(_str->bits_number-i-1)) == 1)

		{
			BUFF[i + 1] = HIGH;

		} else

		{

			BUFF[i + 1] = LOW;

		}
	}
}

void send_hex(uint8_t hex, uint8_t _bits_number, Laser *_str) {
	_str->bits_number = _bits_number;
	readbit(hex, _str);
	HAL_TIM_PWM_Start(_str->pwm, _str->tim_channel);
	HAL_TIM_Base_Start_IT(_str->time_counter);
	time = BUFF[0];
	pause = 1;
}

void time_counter(Laser *_str) {
	if (_str->time_counter->Instance == _str->tim_instance) //check if the interrupt comes from TIM1
			{

		current_time++;
		if (current_time == time) {
			if (pause) {
				HAL_TIM_PWM_Stop(_str->pwm, _str->tim_channel);
				time = TIME_STOP;
				pause = 0;
				current_time = 0;

			}

			else {
				n++;
				if (n > _str->bits_number) {
					HAL_TIM_PWM_Stop(_str->pwm, _str->tim_channel);
					n = 0;
					HAL_TIM_Base_Stop_IT(_str->time_counter);
				} else
					HAL_TIM_PWM_Start(_str->pwm, _str->tim_channel);
				time = BUFF[n];
				pause = 1;
				current_time = 0;

			}
		}

	}
}

void Laser_Init(Laser *_str, TIM_HandleTypeDef *_time_counter,
		TIM_HandleTypeDef *_pwm, uint32_t _tim_channel,
		TIM_TypeDef *_tim_instance) {
	_str->tim_instance = _tim_instance;
	_str->pwm = _pwm;
	_str->tim_channel = _tim_channel;
	_str->time_counter = _time_counter;

}

