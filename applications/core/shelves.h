//
// Created by 天琪王 on 2023/2/20.
//

#ifndef RTTHREAD_SHELVES_H
#define RTTHREAD_SHELVES_H

#include <rtthread.h>

typedef void (* floor_scan)(rt_int8_t floor);

typedef struct {
    rt_int8_t floor;
    floor_scan scan;
} Shelves ;



#endif //RTTHREAD_SHELVES_H
