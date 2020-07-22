/*
 * drvUzSensor.h
 *
 *  Created on: Dec 9, 2019
 *      Author: Slavon
 */

#ifndef SRC_DRVUZSENSOR_H_
#define SRC_DRVUZSENSOR_H_

#include"stm32f4xx.h"
#include"stdint.h"
#include"main.h"

#define    DWT_CYCCNT    *(volatile unsigned long *)0xE0001004
#define    DWT_CONTROL   *(volatile unsigned long *)0xE0001000
#define    SCB_DEMCR     *(volatile unsigned long *)0xE000EDFC
#define    Clock_MCU 	16 // In MHz, it's for converting MCU ticks in uS.
void time_init();
uint32_t Get_uS();
void clean_tick();
void delay_us(uint8_t time);
#endif /* SRC_DRVUZSENSOR_H_ */
