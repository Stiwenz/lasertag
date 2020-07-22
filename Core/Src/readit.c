/*
 * readit.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Slavon
 */

#include "readit.h"

void readbit(){
for(uint8_t i=0;i<8;i++)

	    {

	      if (BitIsSet(hex,(7-i)) == 1)

	      {

	        BUFF[i+1] = HIGH;

	      }else

	      {

	    	  BUFF[i+1] = LOW;

	      }}
}
void send_0(){
	uint32_t current_time_uS = 0;
	if (flag & !end){
		current_time_uS = Get_uS();
		if (current_time_uS >= TIME_STOP){
			HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
			HAL_TIM_Base_Start_IT(&htim3);
			flag = 0;
			clean_tick();
		}
		//HAL_Delay(10);

		//flag = 0;
	}
}
