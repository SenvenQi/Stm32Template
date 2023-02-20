//
// Created by 天琪王 on 2023/2/20.
//

#include "uart.h"
#include "drivers/serial_v2.h"
#include <rtthread.h>
#include <rtdevice.h>

static rt_device_t serial;
static struct rt_semaphore rx_sem;    /* 用于接收消息的信号量 */
struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;  /* 初始化配置参数 */

int open_uart(){
    serial = rt_device_find(UART_NAME);
    serial->open(serial,12);

    /* step2：修改串口配置参数 */
    config.baud_rate = BAUD_RATE_9600;        // 修改波特率为 9600
    config.data_bits = DATA_BITS_8;           // 数据位 8
    config.stop_bits = STOP_BITS_1;           // 停止位 1
    config.rx_bufsz     = 128;                // 修改缓冲区 rx buff size 为 128
    config.parity    = PARITY_NONE;           // 无奇偶校验位

    /* step3：控制串口设备。通过控制接口传入命令控制字，与控制参数 */
    rt_device_control(serial, RT_DEVICE_CTRL_CONFIG, &config);

    return 0;
}

static rt_ssize_t send(){
    char str[] = "hello RT-Thread!\r\n";
    /* step4：打开串口设备。以非阻塞接收和阻塞发送模式打开串口设备 */
    rt_device_open(serial, RT_DEVICE_FLAG_RX_NON_BLOCKING | RT_DEVICE_FLAG_TX_BLOCKING);
    return rt_device_write(serial,0,str,(sizeof(str) - 1));
}
/* 接收数据回调函数 */
static rt_err_t uart_input(rt_device_t dev, rt_size_t size)
{
    /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
    rt_sem_release(&rx_sem);

    return RT_EOK;
}

static int uart_received(int argc, char *argv[])
{
    serial = rt_device_find(UART_NAME);

    /* 初始化信号量 */
    rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);

    /* 设置接收回调函数 */
    rt_device_set_rx_indicate(serial, uart_input);
}
/* 接收数据的线程 */
_Noreturn static void serial_thread_entry(void *parameter)
{
    char ch;

    while (1)
    {
        /* 从串口读取一个字节的数据，没有读取到则等待接收信号量 */
        while (rt_device_read(serial, -1, &ch, 1) != 1)
        {
            /* 阻塞等待接收信号量，等到信号量后再次读取数据 */
            rt_sem_take(&rx_sem, RT_WAITING_FOREVER);
        }
        /* 读取到的数据通过串口错位输出 */
        ch = ch + 1;
        rt_device_write(serial, 0, &ch, 1);
    }
}

INIT_BOARD_EXPORT(open_uart);
