################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UART_Print/Src/UART_Print.c 

C_DEPS += \
./UART_Print/Src/UART_Print.d 

OBJS += \
./UART_Print/Src/UART_Print.o 


# Each subdirectory must supply rules for building sources it contributes
UART_Print/Src/%.o UART_Print/Src/%.su UART_Print/Src/%.cyclo: ../UART_Print/Src/%.c UART_Print/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/STM_Projects/I2C_TMP102-STM32/I2C_Scan/Inc" -I"D:/STM_Projects/I2C_TMP102-STM32/TMP102/Inc" -I"D:/STM_Projects/I2C_TMP102-STM32/UART_Print/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-UART_Print-2f-Src

clean-UART_Print-2f-Src:
	-$(RM) ./UART_Print/Src/UART_Print.cyclo ./UART_Print/Src/UART_Print.d ./UART_Print/Src/UART_Print.o ./UART_Print/Src/UART_Print.su

.PHONY: clean-UART_Print-2f-Src

