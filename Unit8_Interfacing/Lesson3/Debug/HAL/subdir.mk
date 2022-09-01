################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Key_Pad_Driver.c \
../HAL/LCD.c 

OBJS += \
./HAL/Key_Pad_Driver.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/Key_Pad_Driver.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Key_Pad_Driver.o: ../HAL/Key_Pad_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers5/HAL/Includes" -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers5/STM32F103C6_Drivers/INC" -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers5/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Key_Pad_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers5/HAL/Includes" -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers5/STM32F103C6_Drivers/INC" -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers5/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

