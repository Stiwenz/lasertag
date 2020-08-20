/*
 * drvWS2812B.h
 *
 *  Created on: 21 Jan 2020
 *      Author: Slavon
 */

#ifndef INC_READIT_H_
#define INC_READIT_H_
//-- includes --
#include"stm32f0xx.h"
#include"stdint.h"
#include"main.h"
// -------------
//-- define
#define HIGH 12 // 100 uS - is 1 timer period
#define LOW 6
#define HEADER 24
#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)
#define TIME_STOP 6
// -------------

typedef struct {
	TIM_HandleTypeDef *pwm;
	TIM_HandleTypeDef *time_counter;
	uint32_t tim_channel;
	TIM_TypeDef *tim_instance;
	uint8_t bits_number;
} Laser;

void Laser_Init(Laser *_str, TIM_HandleTypeDef *_time_counter,
		TIM_HandleTypeDef *_pwm, uint32_t _tim_channel,
		TIM_TypeDef *_tim_instance);

void time_counter(Laser *_str); // put this function in HAL_TIM_PeriodElapsedCallback
void readbit(uint8_t hex, Laser *_str);
void send_hex(uint8_t hex, uint8_t _bits_number, Laser *_str);

#endif /* INC_READIT_H_ */
