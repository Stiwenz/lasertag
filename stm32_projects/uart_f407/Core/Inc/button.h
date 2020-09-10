/*
 * button.c
 *
 *  Created on: Aug 10, 2020
 *      Author: Viacheslav
 */

#ifndef INC_BUTTON_C_
#define INC_BUTTON_C_
#include "main.h"

typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
}str_button;

uint8_t button(TIM_HandleTypeDef *htim, GPIO_TypeDef * port, uint16_t pin );


#endif /* INC_BUTTON_C_ */


