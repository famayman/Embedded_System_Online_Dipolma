################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_RCC_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_SPI_Driver.c \
../STM32F103C6_Drivers/STM32F103C6_USART_Driver.c 

OBJS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_RCC_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.o \
./STM32F103C6_Drivers/STM32F103C6_USART_Driver.o 

C_DEPS += \
./STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_RCC_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_SPI_Driver.d \
./STM32F103C6_Drivers/STM32F103C6_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.o: ../STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Slave/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.o: ../STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Slave/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_RCC_Driver.o: ../STM32F103C6_Drivers/STM32F103C6_RCC_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Slave/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_RCC_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_SPI_Driver.o: ../STM32F103C6_Drivers/STM32F103C6_SPI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Slave/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_SPI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/STM32F103C6_USART_Driver.o: ../STM32F103C6_Drivers/STM32F103C6_USART_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Slave/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/STM32F103C6_USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
