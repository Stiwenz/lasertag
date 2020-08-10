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


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);

uint8_t read_hex();
#endif /* INC_LASERWAR_RECEIVER_H_ */
