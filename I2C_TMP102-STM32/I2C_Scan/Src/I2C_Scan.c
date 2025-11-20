#include <I2C_Scan.h>

uint8_t i2c_found_addresses[16];

void I2C_Scan(I2C_HandleTypeDef *hi2c, UART_HandleTypeDef *huart){

	uart_print(huart, "Scanning I2C Devices.....\r\n");
	int found = 0;

	for(uint8_t i=1; i<128; i++){
		if(HAL_I2C_IsDeviceReady(hi2c, (i << 1), 1, 10) == HAL_OK){
			i2c_found_addresses[found++] = i;
			uart_print(huart, "I2C Device Address Found : 0x%02X\r\n", i);
		}
	}

	if(found == 0){
		uart_print(huart, "No I2C Device Found....\r\n\n");
	}
	else{
		uart_print(huart, "Scan Complete\r\n\n");
	}
}
