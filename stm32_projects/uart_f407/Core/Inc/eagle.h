/*
 * eagle.h
 *
 *  Created on: Sep 10, 2020
 *      Author: User
 */

#ifndef INC_EAGLE_H_
#define INC_EAGLE_H_
#include "main.h"
typedef enum {
  SAVE_POS = 1,
  SAVE_PREV_POS,
  LEFT,
  RIGHT,
  UP,
  DOWN,
  CHANGE_DIR = 19,

} list_t;

void send(list_t command, uint8_t speed);

#endif /* INC_EAGLE_H_ */
