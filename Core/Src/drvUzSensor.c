/*
 * drvUzSensor.c
 *
 *  Created on: Dec 9, 2019
 *      Author: Slavon
 */

#include "drvUzSensor.h"

//uint32_t current_time_uS = 0;
void time_init(){
	SCB_DEMCR |= 0x01000000;
			  	DWT_CONTROL|= 1;
			  	//DWT_CYCCNT  = 0;

}
uint32_t Get_uS()
{

	uint32_t us_time = DWT_CYCCNT/Clock_MCU;
	 return us_time;

	}


void clean_tick()
{
	DWT_CYCCNT = 0;
}
void delay_us(uint8_t time){
	clean_tick();
	uint8_t current_time = 0;
	while (DWT_CYCCNT/Clock_MCU < time) {
		 current_time = Get_uS();
	}
}
