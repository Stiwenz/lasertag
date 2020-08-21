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

// -------------
//-- define

#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)

// -------------

typedef struct {
	TIM_HandleTypeDef *pwm;
	TIM_HandleTypeDef *time_counter;
	uint32_t tim_channel;
	TIM_TypeDef *tim_instance;
	uint8_t bits_number;
	uint8_t n;
	uint32_t hex;
	uint8_t time;
	uint8_t pause;
	uint8_t current_time;
	uint8_t BUFF[32];
	uint8_t time_high; // 100 uS - is 1 timer period
	uint8_t time_low;
	uint8_t time_header;
	uint8_t time_stop;

} Laser;

void Laser_Init(Laser *_str, TIM_HandleTypeDef *_time_counter,
		TIM_HandleTypeDef *_pwm, uint32_t _tim_channel,
		TIM_TypeDef *_tim_instance, uint8_t _time_high, uint8_t _time_low,
		uint8_t _time_header, uint8_t _time_stop);

void time_counter(Laser *_str, TIM_HandleTypeDef *htim); // put this function in HAL_TIM_PeriodElapsedCallback
void readbit(Laser *_str);
void send_hex(uint32_t hex, uint8_t _bits_number, Laser *_str);


#endif /* INC_READIT_H_ */
