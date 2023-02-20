//
// Created by 天琪王 on 2023/2/20.
//

#include "buzzer.h"
#include <rtthread.h>
#include <board.h>
#include <rtdevice.h>

int Init_Buzzer(){
  rt_pin_mode(BuzzerPIN,PIN_MODE_OUTPUT);
  return 0;
}

INIT_BOARD_EXPORT(Init_Buzzer);