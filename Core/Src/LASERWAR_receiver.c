/*
 * LASERWAR_receiver.c
 *
 *  Created on: 10 Aug 2020
 *      Author: User
 */
#include "LASERWAR_receiver.h"

// void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)

void interrupt(laserwar *rx, TIM_HandleTypeDef *htim) {
	//extern TIM_HandleTypeDef htim3;
	rx->time = 0;
	if (htim->Instance == rx->fronts_capture) {
		if (htim->Channel == rx->tim_ch_fall_active) //FALLING
				{
			rx->fronts_capture->CNT = 0; // обнуление счётчика
		} else if (htim->Channel == rx->tim_ch_rise_active) // RISING
				{
			rx->time = rx->fronts_capture->CNT;
			if (rx->time >= 2300 && rx->time <= 3000)
				rx->start_reading = 1;
			if ((rx->start_reading)
					&& ((rx->time >= 400 && rx->time <= 700)
							|| (rx->time >= 1000 && rx->time <= 1300))) {
				rx->BUFF[rx->n] = rx->time;
				rx->n++;
				if(rx->n == 20)
					 asm("NOP");

			}
		}
	}
}

uint32_t read_hex(laserwar *rx) {
	uint32_t hex = 0;
	uint8_t n = 0;
	for (uint8_t i = rx->n-1; i <= rx->n-1; i--) {
		if (rx->BUFF[i] >= 1000 && rx->BUFF[i] <= 1300) {

			hex |= 1 << n; //set the bit in the variable
		}
		n++;
	}
	return hex;

}

void Laser_Init(laserwar *rx, TIM_HandleTypeDef *_tim_interrupt,
		TIM_HandleTypeDef *_time_counter, uint32_t _tim_ch_fall,
		uint32_t _tim_ch_rise, TIM_TypeDef *_fronts_capture, TIM_TypeDef *_counter_intr){
	rx->time_counter = _time_counter;
	rx->tim_interrupt = _tim_interrupt;
	rx->tim_ch_fall = _tim_ch_fall;
	rx->tim_ch_rise = _tim_ch_rise;
	rx->fronts_capture = _fronts_capture;
	rx->counter_intr = _counter_intr;
	HAL_TIM_IC_Start_IT(rx->tim_interrupt, rx->tim_ch_fall);
	HAL_TIM_IC_Start_IT(rx->tim_interrupt, rx->tim_ch_rise);
	HAL_TIM_Base_Start_IT(rx->time_counter);
	rx->tim_ch_rise_active = channel_init(_tim_ch_rise);
	rx->tim_ch_fall_active = channel_init(_tim_ch_fall);
	}


void pack_ended (laserwar *rx, TIM_HandleTypeDef *htim){
	if (htim->Instance == rx->counter_intr){
	uint32_t timer_value = rx->fronts_capture->CNT;
	if (timer_value >= 3000 && rx->start_reading) {
						rx->value = read_hex(rx);
						rx->n = 0;
						rx->start_reading = 0;
					}
}
}
uint8_t channel_init(uint32_t tim_channel) {
	switch (tim_channel) {
	case TIM_CHANNEL_1:
		return HAL_TIM_ACTIVE_CHANNEL_1;
		break;
	case TIM_CHANNEL_2:
		return HAL_TIM_ACTIVE_CHANNEL_2;
		break;
	case TIM_CHANNEL_3:
		return HAL_TIM_ACTIVE_CHANNEL_3;
		break;
	case TIM_CHANNEL_4:
		return HAL_TIM_ACTIVE_CHANNEL_4;
		break;
	default: return 0;
	}
}
