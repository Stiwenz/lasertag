/*
 * drvWS2812B.h
 *
 *  Created on: 21 Jan 2020
 *      Author: Slavon
 */

#ifndef INC_READIT_H_
#define INC_READIT_H_
//-- includes --
#include"stm32f4xx.h"
#include"stdint.h"
#include"main.h"
// -------------
//-- define
#define HIGH 46
#define LOW 23
#define BitIsSet(reg, bit) ((reg & (1<<bit)) != 0)
#define TIME_STOP 600

// -------------


// variables
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern uint8_t end;
extern uint32_t pulse_counter;
extern uint8_t flag;
extern uint8_t hex;
extern uint8_t BUFF[9];
extern uint8_t flag;

//

void readbit();
void send_0();
#endif /* INC_READIT_H_ */
