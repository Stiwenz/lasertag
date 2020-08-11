/*
 * readit.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Slavon
 */


#include <LASERWAR.h>

void readbit(uint8_t hex){
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
void send_1(){
	uint32_t current_time_uS = 0;
	if (flag & !end){
HAL_Delay(1);
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
			HAL_TIM_Base_Start_IT(&htim1);
			flag = 0;
			clean_tick();

	}
}

void send_0() {
	start = 1;
	pulse_counter++;
	if(pulse_counter >= BUFF[n]){
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
	HAL_TIM_Base_Stop_IT(&htim1);
	flag = 1;
	n++;
	clean_tick();
	pulse_counter = 0;
	if (n > 8)
	{
	end = 1;
		n=0;
	start =0;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	}
}}
void send_hex(uint8_t hex){

	BUFF[0] = HEADER;

	readbit(hex);
	if (!start){
	  HAL_TIM_Base_Start_IT(&htim1);
	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	}
	if (!start_pack)
	send_1();


}
void start_radiation()
{
	start_pack = 0;
	end = 0;
}

