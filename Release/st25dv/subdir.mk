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
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L053xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-st25dv

clean-st25dv:
	-$(RM) ./st25dv/st25dv.cyclo ./st25dv/st25dv.d ./st25dv/st25dv.o ./st25dv/st25dv.su ./st25dv/st25dv_reg.cyclo ./st25dv/st25dv_reg.d ./st25dv/st25dv_reg.o ./st25dv/st25dv_reg.su

.PHONY: clean-st25dv

