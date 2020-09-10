/*
 * eagle.c
 *
 *  Created on: Sep 10, 2020
 *      Author: User
 */
#include "eagle.h"
extern UART_HandleTypeDef huart2;
void send(list_t command , uint8_t speed) {
	uint8_t buff[5] = { 255, 1, command, speed };
	buff[4] = (buff[1] + buff[2] + buff[3]) % 128;
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, SET);
	HAL_UART_Transmit(&huart2, (uint8_t*) buff, sizeof(buff), 10);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, RESET);
}
