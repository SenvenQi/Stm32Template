//
// Created by 天琪王 on 2023/2/20.
//

#ifndef RTTHREAD_UART_H
#define RTTHREAD_UART_H

#include "rtdef.h"

#define UART_NAME "uart1"
static rt_ssize_t send();

_Noreturn static void serial_thread_entry(void *parameter);

#endif //RTTHREAD_UART_H
