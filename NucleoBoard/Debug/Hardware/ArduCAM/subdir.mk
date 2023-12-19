################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/ArduCAM/ArduCAMCustom.c 

C_DEPS += \
./Hardware/ArduCAM/ArduCAMCustom.d 

OBJS += \
./Hardware/ArduCAM/ArduCAMCustom.o 


# Each subdirectory must supply rules for building sources it contributes
Hardware/ArduCAM/%.o Hardware/ArduCAM/%.su Hardware/ArduCAM/%.cyclo: ../Hardware/ArduCAM/%.c Hardware/ArduCAM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DCORE_CM4 -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../tensorflow -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -I../Hardware/ArduCAM -I../Hardware/I2C -I../Hardware/SPI -I../System/delay -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Hardware-2f-ArduCAM

clean-Hardware-2f-ArduCAM:
	-$(RM) ./Hardware/ArduCAM/ArduCAMCustom.cyclo ./Hardware/ArduCAM/ArduCAMCustom.d ./Hardware/ArduCAM/ArduCAMCustom.o ./Hardware/ArduCAM/ArduCAMCustom.su

.PHONY: clean-Hardware-2f-ArduCAM

