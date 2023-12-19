################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../tensorflow/tensorflow/lite/c/common.c 

C_DEPS += \
./tensorflow/tensorflow/lite/c/common.d 

OBJS += \
./tensorflow/tensorflow/lite/c/common.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/c/%.o tensorflow/tensorflow/lite/c/%.su tensorflow/tensorflow/lite/c/%.cyclo: ../tensorflow/tensorflow/lite/c/%.c tensorflow/tensorflow/lite/c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DCORE_CM4 -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../tensorflow -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -I../Hardware/ArduCAM -I../Hardware/I2C -I../Hardware/SPI -I../System/delay -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-c

clean-tensorflow-2f-tensorflow-2f-lite-2f-c:
	-$(RM) ./tensorflow/tensorflow/lite/c/common.cyclo ./tensorflow/tensorflow/lite/c/common.d ./tensorflow/tensorflow/lite/c/common.o ./tensorflow/tensorflow/lite/c/common.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-c

