#include <TMP102.h>

int16_t TMP102_ReadRawTemp(I2C_HandleTypeDef *hi2c)
{
    uint8_t reg = 0x00; // temperature register
    uint8_t data[2];

    if (HAL_I2C_Master_Transmit(hi2c, TMP102_I2C_ADDR, &reg, 1, 100) != HAL_OK)
        return -1;

    if (HAL_I2C_Master_Receive(hi2c, TMP102_I2C_ADDR, data, 2, 100) != HAL_OK)
        return -1;

    int16_t raw = ((data[0] << 8) | data[1]) >> 4;

    // sign extend for negative temperatures
    if (raw & 0x800)
        raw |= 0xF000;

    return raw;
}


float TMP102_ReadTempC(I2C_HandleTypeDef *hi2c)
{
    int16_t raw = TMP102_ReadRawTemp(hi2c);

    if (raw == -1)
        return -1000;

    return raw * 0.0625f;
}

float TMP102_ReadTempF(I2C_HandleTypeDef *hi2c)
{
    float c = TMP102_ReadTempC(hi2c);

    if (c == -1000)
        return -1000;

    return (c * 9.0f/5.0f) + 32.0f; // Convert °C → °F
}
