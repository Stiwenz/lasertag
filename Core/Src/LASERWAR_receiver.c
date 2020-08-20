/*
 * LASERWAR_receiver.c
 *
 *  Created on: 10 Aug 2020
 *      Author: User
 */
#include "LASERWAR_receiver.h"

// void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)

void interrupt(laserwar *rx, TIM_HandleTypeDef *htim) {
	uint16_t time = 0;
	if (htim->Instance == rx->tim_instance) {
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) //FALLING
				{
			__HAL_TIM_SET_COUNTER(rx->tim_interrupt, 0x0000); // обнуление счётчика
		} else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) // RISING
				{
			time = HAL_TIM_ReadCapturedValue(rx->tim_interrupt, TIM_CHANNEL_2);
			if (time >= 2400 && time <= 3000)
				rx->start_reading = 1;
			if ((rx->start_reading)
					&& ((time >= 400 && time <= 700)
							|| (time >= 1000 && time <= 1300))) {
				rx->BUFF[rx->n] = time;
				rx->n++;
				if (rx->n >= 8) {
					rx->n = 0;
					rx->start_reading = 0;
					rx->value = read_hex(rx);
				}
			}
		}
	}
}

uint8_t read_hex(laserwar *rx) {
	uint8_t hex = 0;
	uint8_t n = 0;
	for (uint8_t i = 7; i <= 7; i--) {
		if (rx->BUFF[i] >= 1000 && rx->BUFF[i] <= 1300) {

			hex |= 1 << n; //set the bit in the variable
		}
		n++;
	}
	return hex;

}

void Laser_Init(laserwar *rx, TIM_HandleTypeDef *_tim_interrupt,
		uint32_t _tim_ch_fall, uint32_t _tim_ch_rise,
		TIM_TypeDef *_tim_instance) {
	rx->tim_interrupt = _tim_interrupt;
	rx->tim_ch_fall = _tim_ch_fall;
	rx->tim_ch_rise = _tim_ch_rise;
	rx->tim_instance = _tim_instance;
	HAL_TIM_IC_Start_IT(rx->tim_interrupt, rx->tim_ch_fall);
	HAL_TIM_IC_Start_IT(rx->tim_interrupt, rx->tim_ch_rise);
}
