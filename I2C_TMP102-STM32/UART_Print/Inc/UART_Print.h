#ifndef UART_PRINT_H
#define UART_PRINT_H

#include <stm32f4xx_hal.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void uart_print(UART_HandleTypeDef *huart, const char *ch, ...);

#endif
