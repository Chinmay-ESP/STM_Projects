#ifndef TMP102_H
#define TMP102_H

#include "stm32f4xx_hal.h"

#define TMP102_I2C_ADDR (0x48 << 1)

int16_t TMP102_ReadRawTemp(I2C_HandleTypeDef *hi2c);
float TMP102_ReadTempC(I2C_HandleTypeDef *hi2c);
float TMP102_ReadTempF(I2C_HandleTypeDef *hi2c);

#endif
