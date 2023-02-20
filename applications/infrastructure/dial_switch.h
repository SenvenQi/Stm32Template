//
// Created by 天琪王 on 2023/2/20.
//

#ifndef RTTHREAD_DIAL_SWITCH_H
#define RTTHREAD_DIAL_SWITCH_H

#include <board.h>

#define DIAL1 GET_PIN(B,12)
#define DIAL2 GET_PIN(B,13)
#define DIAL3 GET_PIN(B,14)
#define DIAL4 GET_PIN(B,15)
#define DIAL5 GET_PIN(C,6)
#define DIAL6 GET_PIN(C,7)
#define DIAL7 GET_PIN(C,8)
#define DIAL8 GET_PIN(C,9)
rt_int8_t read_data();

#endif //RTTHREAD_DIAL_SWITCH_H
