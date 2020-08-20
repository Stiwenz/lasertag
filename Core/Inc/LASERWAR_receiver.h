/*
 * LASERWAR_receiver.h
 *
 *  Created on: Aug 10, 2020
 *      Author: User
 */

#ifndef INC_LASERWAR_RECEIVER_H_
#define INC_LASERWAR_RECEIVER_H_

#include "main.h"
#include "math.h"

typedef struct {
	uint32_t value;
	uint8_t buffer;
	uint8_t n;
	uint8_t end;
	uint8_t start_reading;
	uint16_t BUFF[8];
	TIM_HandleTypeDef *tim_interrupt;
	TIM_TypeDef *tim_instance;
	uint32_t tim_ch_fall;
	uint32_t tim_ch_rise;
}laserwar;


void interrupt(laserwar *rx,TIM_HandleTypeDef *htim);
uint8_t read_hex(laserwar *rx);
void Laser_Init(laserwar *rx, TIM_HandleTypeDef *_tim_interrupt, uint32_t _tim_ch_fall,
		uint32_t _tim_ch_rise, TIM_TypeDef *_tim_instance);
#endif /* INC_LASERWAR_RECEIVER_H_ */
