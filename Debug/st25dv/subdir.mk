################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../st25dv/st25dv.c \
../st25dv/st25dv_reg.c 

OBJS += \
./st25dv/st25dv.o \
./st25dv/st25dv_reg.o 

C_DEPS += \
./st25dv/st25dv.d \
./st25dv/st25dv_reg.d 


# Each subdirectory must supply rules for building sources it contributes
st25dv/%.o st25dv/%.su st25dv/%.cyclo: ../st25dv/%.c st25dv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../../st23dv -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/mkoza/STM32CubeIDE/workspace_1.12.0/DISCO-eink-NFC/epd-lib" -I"C:/Users/mkoza/STM32CubeIDE/workspace_1.12.0/DISCO-eink-NFC/epd-lib/Config" -I"C:/Users/mkoza/STM32CubeIDE/workspace_1.12.0/DISCO-eink-NFC/epd-lib/e-Paper" -I"C:/Users/mkoza/STM32CubeIDE/workspace_1.12.0/DISCO-eink-NFC/epd-lib/Fonts" -I"C:/Users/mkoza/STM32CubeIDE/workspace_1.12.0/DISCO-eink-NFC/epd-lib/GUI" -I"C:/Users/mkoza/STM32CubeIDE/workspace_1.12.0/DISCO-eink-NFC/Core/Inc" -I../Core/Inc -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-st25dv

clean-st25dv:
	-$(RM) ./st25dv/st25dv.cyclo ./st25dv/st25dv.d ./st25dv/st25dv.o ./st25dv/st25dv.su ./st25dv/st25dv_reg.cyclo ./st25dv/st25dv_reg.d ./st25dv/st25dv_reg.o ./st25dv/st25dv_reg.su

.PHONY: clean-st25dv

