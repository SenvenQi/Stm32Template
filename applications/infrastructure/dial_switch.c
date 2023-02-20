//
// Created by 天琪王 on 2023/2/20.
//
#include <board.h>
#include "dial_switch.h"

int init_dial_switch(){
    rt_pin_mode(DIAL1,PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(DIAL2,PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(DIAL3,PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(DIAL4,PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(DIAL5,PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(DIAL6,PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(DIAL7,PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(DIAL8,PIN_MODE_INPUT_PULLUP);
    return 0;
}

rt_int8_t read_data(){
   int dial1 = rt_pin_read(DIAL1);
   int dial2 =  rt_pin_read(DIAL2);
   int dial3 = rt_pin_read(DIAL3);
   int dial4 = rt_pin_read(DIAL4);
   int dial5 = rt_pin_read(DIAL5);
   int dial6 = rt_pin_read(DIAL6);
   int dial7 = rt_pin_read(DIAL7);
   int dial8 = rt_pin_read(DIAL8);
    return dial1 + (dial2<<1) + (dial3<<2) + (dial4<<3) + (dial5<<4) + (dial6<<5) + (dial7<<6) + (dial8<<7) ;
}

INIT_BOARD_EXPORT(init_dial_switch);