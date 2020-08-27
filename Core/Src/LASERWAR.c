/*
 * readit.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Slavon
 */

#include <LASERWAR.h>

// variables

//Laser *_str;

/////////


void readbit( Laser *_str) {
	_str->BUFF[0] = _str->time_header;
	for (uint8_t i = 0; i < _str->bits_number; i++) {

		if (BitIsSet(_str->hex,(_str->bits_number-i-1)) == 1)

		{
			_str->BUFF[i + 1] = _str->time_high;

		} else

		{

			_str->BUFF[i + 1] = _str->time_low;

		}
	}
}

void send_hex(uint32_t hex, uint8_t _bits_number, Laser *_str) {
	_str->hex = hex;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);  // comment it if you use another board
	_str->bits_number = _bits_number;
	readbit(_str);
	_str->flag = 1;
	_str->time = _str->BUFF[0];
	_str->pause = 1;
}

void time_counter(Laser *_str, TIM_HandleTypeDef *htim) {
	if (htim->Instance == _str->tim_instance) //check if the interrupt comes from TIM1
			{
		if (_str->flag){
		HAL_TIM_PWM_Start(_str->pwm, _str->tim_channel);
		_str->flag = 0;
		_str->current_time = 0;
		 _str->started = 1;
		}
		_str->current_time++;
		if (_str->current_time == _str->time && _str->started) {
			if (_str->pause){
				HAL_TIM_PWM_Stop(_str->pwm, _str->tim_channel);
				_str->time = _str->time_stop;
				_str->pause = 0;
				_str->current_time = 0;

			}

			else {
				_str->n++;
				if (_str->n > _str->bits_number && _str->started) {
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET); // comment it if you use another board
					HAL_TIM_PWM_Stop(_str->pwm, _str->tim_channel);
					_str->n = 0;
					//HAL_TIM_Base_Stop_IT(_str->time_counter);
					_str->started = 0;
				} else if (_str->started)
					HAL_TIM_PWM_Start(_str->pwm, _str->tim_channel);
				_str->time = _str->BUFF[_str->n];
				_str->pause = 1;
				_str->current_time = 0;

			}
		}

	}
}

void Laser_Init(Laser *_str, TIM_HandleTypeDef *_time_counter,
		TIM_HandleTypeDef *_pwm, uint32_t _tim_channel,
		TIM_TypeDef *_tim_instance, uint8_t _time_high, uint8_t _time_low,
		uint8_t _time_header, uint8_t _time_stop) {
	_str->tim_instance = _tim_instance;
	_str->pwm = _pwm;
	_str->tim_channel = _tim_channel;
	_str->time_counter = _time_counter;
	_str->time_high = _time_high;
	_str->time_low = _time_low;
	_str->time_header = _time_header;
	_str->time_stop = _time_stop;
	HAL_TIM_Base_Start_IT(_str->time_counter);

}
