################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/I2C_Slave_EEPROM.c \
../STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_I2C_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_RCC_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_SPI_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_USART_Driver.c 

OBJS += \
./STM32F103C6_Drivers/I2C_Slave_EEPROM.o \
./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_RCC_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_USART_Driver.o 

C_DEPS += \
./STM32F103C6_Drivers/I2C_Slave_EEPROM.d \
./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_RCC_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/%.o STM32F103C6_Drivers/%.su: ../STM32F103C6_Drivers/%.c STM32F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Unit8_Lesson7/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers

clean-STM32F103C6_Drivers:
	-$(RM) ./STM32F103C6_Drivers/I2C_Slave_EEPROM.d ./STM32F103C6_Drivers/I2C_Slave_EEPROM.o ./STM32F103C6_Drivers/I2C_Slave_EEPROM.su ./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.d ./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.o ./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.su ./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d ./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o ./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.su ./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.d ./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.o ./STM32F103C6_Drivers/STM32F103C6_I2C_Driver.su ./STM32F103C6_Drivers/STM32F103C6_RCC_Driver.d ./STM32F103C6_Drivers/STM32F103C6_RCC_Driver.o ./STM32F103C6_Drivers/STM32F103C6_RCC_Driver.su ./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.d ./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.o ./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.su ./STM32F103C6_Drivers/STM32F103C6_USART_Driver.d ./STM32F103C6_Drivers/STM32F103C6_USART_Driver.o ./STM32F103C6_Drivers/STM32F103C6_USART_Driver.su

.PHONY: clean-STM32F103C6_Drivers

