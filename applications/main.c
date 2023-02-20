/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-06     SummerGift   first version
 */

#include "infrastructure/uart.h"
#include "rtthread.h"


int main(void)
{
    rt_thread_t thread;
    thread = rt_thread_create("uart", &serial_thread_entry, RT_NULL, 1024, 10, 1000);
    rt_thread_startup(thread);
    /* set LED0 pin mode to output */
    while (1);
}
