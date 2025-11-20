#include "UART_Print.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void uart_print(UART_HandleTypeDef *huart, const char *fmt, ...)
{
    char buffer[256];

    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    HAL_UART_Transmit(huart, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}
