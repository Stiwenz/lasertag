/*
 * LASERWAR_receiver.h
 *
 *  Created on: Aug 10, 2020
 *      Author: User
 */

#ifndef INC_LASERWAR_RECEIVER_H_
#define INC_LASERWAR_RECEIVER_H_

#include"stm32f0xx.h"
#include"stdint.h"

typedef struct {
	uint32_t value;
	uint32_t buffer;
	uint8_t n;
	uint8_t end;
	uint8_t start_reading;
	uint32_t BUFF[32];
	TIM_HandleTypeDef *tim_interrupt;
	TIM_TypeDef *fronts_capture;
	TIM_TypeDef *counter_intr;
	TIM_HandleTypeDef *time_counter;
	uint32_t tim_ch_fall;
	uint32_t tim_ch_fall_active;
	uint32_t tim_ch_rise;
	uint32_t tim_ch_rise_active;
	uint32_t tim_ch_rise_ccr;
	uint32_t time;
} laserwar;

void interrupt(laserwar *rx, TIM_HandleTypeDef *htim);
uint32_t read_hex(laserwar *rx);
void Laser_Init(laserwar *rx, TIM_HandleTypeDef *_tim_interrupt,
		TIM_HandleTypeDef *_time_counter, uint32_t _tim_ch_fall,
		uint32_t _tim_ch_rise, TIM_TypeDef *_fronts_capture,
		TIM_TypeDef *counter_intr);
void pack_ended(laserwar *rx, TIM_HandleTypeDef *htim);
uint8_t channel_init(uint32_t tim_channel);
#endif /* INC_LASERWAR_RECEIVER_H_ */
