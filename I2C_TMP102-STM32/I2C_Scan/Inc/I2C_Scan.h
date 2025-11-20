#ifndef I2C_Scan_H
#define I2C_Scan_H

#include <stm32f4xx_hal.h>
#include <stdio.h>
#include <UART_Print.h>

void I2C_Scan(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart);

#endif
