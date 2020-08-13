/*
 * readit.c
 *
 *  Created on: Jul 12, 2020
 *      Author: Slavon
 */


#include <LASERWAR.h>

uint8_t end;
uint8_t start_pack;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
uint32_t pulse_counter;
uint8_t flag;
extern uint16_t BUFF[9];
uint8_t n;
uint16_t BUFF[9];
uint8_t hex;

extern TIM_HandleTypeDef htim15;

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
	//uint32_t current_time_uS = 0;
	if(!end){
	HAL_TIM_Base_Stop_IT(&htim15);
			HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
			HAL_TIM_Base_Start_IT(&htim1);
			//flag = 0;
		//	clean_tick();
	}


}

void send_0() {
	if (!end){
	start_pack = 1;
	pulse_counter++;
	if(pulse_counter >= BUFF[n]){
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
	HAL_TIM_Base_Stop_IT(&htim1);
	TIM15->CNT = 0;
	HAL_TIM_Base_Start_IT(&htim15);
	//flag = 1;
	n++;
	pulse_counter = 0;
	if (n > 8)
	{
	end = 1;
		n=0;
		start_pack = 0;
	HAL_TIM_Base_Stop_IT(&htim15);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	}
}}}

void send_hex(uint8_t hex){
	//if (!start_pack){

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET); // current source soft on
		end = 0;
		BUFF[0] = HEADER;
		readbit(hex);
		HAL_TIM_Base_Start_IT(&htim1);
		HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);


	//}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
        if(htim->Instance == TIM15) //check if the interrupt comes from TIM15
        {
               send_1();
        }
}
