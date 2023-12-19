################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size.cc \
../tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper.cc \
../tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper_pybind.cc 

CC_DEPS += \
./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size.d \
./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper.d \
./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper_pybind.d 

OBJS += \
./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size.o \
./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper.o \
./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper_pybind.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/tensorflow/lite/micro/python/tflite_size/src/%.o tensorflow/tensorflow/lite/micro/python/tflite_size/src/%.su tensorflow/tensorflow/lite/micro/python/tflite_size/src/%.cyclo: ../tensorflow/tensorflow/lite/micro/python/tflite_size/src/%.cc tensorflow/tensorflow/lite/micro/python/tflite_size/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-python-2f-tflite_size-2f-src

clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-python-2f-tflite_size-2f-src:
	-$(RM) ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size.cyclo ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size.d ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size.o ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size.su ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper.cyclo ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper.d ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper.o ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper.su ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper_pybind.cyclo ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper_pybind.d ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper_pybind.o ./tensorflow/tensorflow/lite/micro/python/tflite_size/src/flatbuffer_size_wrapper_pybind.su

.PHONY: clean-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-python-2f-tflite_size-2f-src

