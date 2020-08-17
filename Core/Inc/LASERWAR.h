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




void readbit(uint8_t hex);
void send_hex(uint8_t hex);
#endif /* INC_READIT_H_ */
