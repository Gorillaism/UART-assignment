#ifndef __MY_STM32F4_UART_LIB_H__
#define __MY_STM32F4_UART_LIB_H__

#include "my_stm32f4_uart_driver.h"
#include "my_stm32f4_gpio_lib.h"

void UART2_init(GPIO_TypeDef* GPIOx);

void UART2_enable(UART_TypeDef* UART, int baudrate_option);

void UART2_disable(UART_TypeDef* UART);

int UART2_write(int ch);

int UART2_read(void);

void UART2_setBBR(UART_TypeDef* UART, uint16_t rate);

#endif