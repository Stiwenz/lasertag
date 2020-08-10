/*
 * LASERWAR_receiver.c
 *
 *  Created on: 10 Aug 2020
 *      Author: User
 */
#include "LASERWAR_receiver.h"

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) // колбек по захвату
{
	extern uint8_t value;
	extern TIM_HandleTypeDef htim3;
	extern uint16_t BUFF[8];
	static uint8_t n = 0;
	static uint8_t end = 0;
	static uint8_t start_reading = 0;

	uint16_t time = 0;
	if(htim->Instance == TIM3)
	        {
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1) //FALLING
	                {
	                        __HAL_TIM_SET_COUNTER(&htim3, 0x0000); // обнуление счётчика
	                }
	 else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) // RISING
	                {
 time = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_2);
if(time >= 2400 && time <=3000)
	start_reading = 1;
if((start_reading) && ((time >= 400 && time <=700)||(time >= 1000 && time <=1300))){
BUFF[n] = time;
n++;
if (n>=8){
	n=0;
	start_reading = 0;
	value = read_hex();
}
	              }
	                }
	        }
}

uint8_t read_hex(){
extern uint16_t BUFF[8];
uint8_t hex = 0;
uint8_t n = 0;
	for(uint8_t i=7;i<=7;i--)
	    {
if(BUFF[i] >= 1000 && BUFF[i] <=1300)
{

hex |=1<<n; //set the bit in the variable
}
n++;
	     }
	return hex;

}
