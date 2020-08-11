/*
 * drvUzSensor.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Slavon
 */

#include <get_us.h>

//uint32_t current_time_uS = 0;
void time_init(){
	SCB_DEMCR |= 0x01000000;
			  	DWT_CONTROL|= 1;
			  	DWT_CYCCNT  = 0;

}
uint32_t Get_uS() // return the time in uS
{

	uint32_t us_time = DWT_CYCCNT/Clock_MCU;
	 return us_time;

	}


void clean_tick() //cleaning clock register
{
	DWT_CYCCNT = 0;
}
void delay_us(uint8_t time){ // delay function in uS
	clean_tick();
	uint8_t current_time = 0;
	while (current_time < time) {
		 current_time = Get_uS();
	}
}
uint8_t botton_pressed (){
	uint8_t counter;
	uint8_t measured;
	uint32_t start_time;
	if(!measured)
	{
	start_time = HAL_GetTick();
	measured = 1;
	}
	uint32_t current_time = HAL_GetTick();
	if(current_time - start_time >= 20){
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == RESET){
		 counter++;
		 current_time = 0;
		if (counter>=10)
		{
			measured = 0;
			return 1;
		}
		else return 0;
		}
	else {
		counter = 0;
		return 0;
	}
	}


}
