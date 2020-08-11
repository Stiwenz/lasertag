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
#define HIGH 46
#define LOW 23
#define HEADER 102
#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)
#define TIME_STOP 600

// -------------


// variables
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
uint8_t end;
uint32_t pulse_counter;
uint8_t flag;
extern uint16_t BUFF[9];
uint8_t n;
uint16_t BUFF[9];
uint8_t hex;
 uint8_t start;
extern uint8_t start_pack;
//

void readbit(uint8_t hex);
void send_0();
void send_1();
void send_hex(uint8_t hex);
#endif /* INC_READIT_H_ */
