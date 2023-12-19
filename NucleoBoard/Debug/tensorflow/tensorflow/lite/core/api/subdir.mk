################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/tensorflow/lite/core/api/error_reporter.cc \
../tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.cc \
../tensorflow/tensorflow/lite/core/api/op_resolver.cc \
../tensorflow/tensorflow/lite/core/api/tensor_utils.cc 

CC_DEPS += \
./tensorflow/tensorflow/lite/core/api/error_reporter.d \
./tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.d \
./tensorflow/tensorflow/lite/core/api/op_resolver.d \
./tensorflow/tensorflow/lite/core/api/tensor_utils.d 

OBJS += \
./tensorflow/tensorflow/lite/core/api/error_reporter.o \
./tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.o \
./tensorflow/tensorflow/lite/core/api/op_resolver.o \
./tensorflow/tensorflow/lite/core/api/tensor_utils.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/core/api/%.o tensorflow/tensorflow/lite/core/api/%.su tensorflow/tensorflow/lite/core/api/%.cyclo: ../tensorflow/tensorflow/lite/core/api/%.cc tensorflow/tensorflow/lite/core/api/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DCORE_CM4 -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../tensorflow -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -I../Hardware/ArduCAM -I../Hardware/I2C -I../Hardware/SPI -I../System/delay -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-core-2f-api

clean-tensorflow-2f-tensorflow-2f-lite-2f-core-2f-api:
	-$(RM) ./tensorflow/tensorflow/lite/core/api/error_reporter.cyclo ./tensorflow/tensorflow/lite/core/api/error_reporter.d ./tensorflow/tensorflow/lite/core/api/error_reporter.o ./tensorflow/tensorflow/lite/core/api/error_reporter.su ./tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.cyclo ./tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.d ./tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.o ./tensorflow/tensorflow/lite/core/api/flatbuffer_conversions.su ./tensorflow/tensorflow/lite/core/api/op_resolver.cyclo ./tensorflow/tensorflow/lite/core/api/op_resolver.d ./tensorflow/tensorflow/lite/core/api/op_resolver.o ./tensorflow/tensorflow/lite/core/api/op_resolver.su ./tensorflow/tensorflow/lite/core/api/tensor_utils.cyclo ./tensorflow/tensorflow/lite/core/api/tensor_utils.d ./tensorflow/tensorflow/lite/core/api/tensor_utils.o ./tensorflow/tensorflow/lite/core/api/tensor_utils.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-core-2f-api

