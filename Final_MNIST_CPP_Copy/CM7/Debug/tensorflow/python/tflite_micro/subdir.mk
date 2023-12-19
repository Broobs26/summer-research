################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/python/tflite_micro/_runtime.cc \
../tensorflow/python/tflite_micro/interpreter_wrapper.cc \
../tensorflow/python/tflite_micro/numpy_utils.cc \
../tensorflow/python/tflite_micro/python_ops_resolver.cc \
../tensorflow/python/tflite_micro/python_utils.cc 

CC_DEPS += \
./tensorflow/python/tflite_micro/_runtime.d \
./tensorflow/python/tflite_micro/interpreter_wrapper.d \
./tensorflow/python/tflite_micro/numpy_utils.d \
./tensorflow/python/tflite_micro/python_ops_resolver.d \
./tensorflow/python/tflite_micro/python_utils.d 

OBJS += \
./tensorflow/python/tflite_micro/_runtime.o \
./tensorflow/python/tflite_micro/interpreter_wrapper.o \
./tensorflow/python/tflite_micro/numpy_utils.o \
./tensorflow/python/tflite_micro/python_ops_resolver.o \
./tensorflow/python/tflite_micro/python_utils.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/python/tflite_micro/%.o tensorflow/python/tflite_micro/%.su tensorflow/python/tflite_micro/%.cyclo: ../tensorflow/python/tflite_micro/%.cc tensorflow/python/tflite_micro/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-python-2f-tflite_micro

clean-tensorflow-2f-python-2f-tflite_micro:
	-$(RM) ./tensorflow/python/tflite_micro/_runtime.cyclo ./tensorflow/python/tflite_micro/_runtime.d ./tensorflow/python/tflite_micro/_runtime.o ./tensorflow/python/tflite_micro/_runtime.su ./tensorflow/python/tflite_micro/interpreter_wrapper.cyclo ./tensorflow/python/tflite_micro/interpreter_wrapper.d ./tensorflow/python/tflite_micro/interpreter_wrapper.o ./tensorflow/python/tflite_micro/interpreter_wrapper.su ./tensorflow/python/tflite_micro/numpy_utils.cyclo ./tensorflow/python/tflite_micro/numpy_utils.d ./tensorflow/python/tflite_micro/numpy_utils.o ./tensorflow/python/tflite_micro/numpy_utils.su ./tensorflow/python/tflite_micro/python_ops_resolver.cyclo ./tensorflow/python/tflite_micro/python_ops_resolver.d ./tensorflow/python/tflite_micro/python_ops_resolver.o ./tensorflow/python/tflite_micro/python_ops_resolver.su ./tensorflow/python/tflite_micro/python_utils.cyclo ./tensorflow/python/tflite_micro/python_utils.d ./tensorflow/python/tflite_micro/python_utils.o ./tensorflow/python/tflite_micro/python_utils.su

.PHONY: clean-tensorflow-2f-python-2f-tflite_micro

