################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/LCD_Driver/LCD.c 

OBJS += \
./STM32F103C6_Drivers/LCD_Driver/LCD.o 

C_DEPS += \
./STM32F103C6_Drivers/LCD_Driver/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/LCD_Driver/LCD.o: ../STM32F103C6_Drivers/LCD_Driver/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers2/STM32F103C6_Drivers/LCD_Driver" -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers2/STM32F103C6_Drivers/Keypad_Driver" -I"C:/Users/Fam Ayman/STM32CubeIDE/workspace_1.4.6/Drivers2/STM32F103C6_Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/LCD_Driver/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

