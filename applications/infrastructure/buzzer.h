//
// Created by 天琪王 on 2023/2/20.
//

#ifndef RTTHREAD_BUZZER_H
#define RTTHREAD_BUZZER_H

#define BuzzerPIN GET_PIN(A,6)
#define BuzzerON rt_pin_write(BuzzerPIN,PIN_HIGH);
#define BuzzerOFF rt_pin_write(BuzzerPIN,PIN_LOW)

#endif //RTTHREAD_BUZZER_H
