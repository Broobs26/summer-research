################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_float.cc \
../tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int16.cc \
../tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int32.cc 

CC_DEPS += \
./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_float.d \
./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int16.d \
./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int32.d 

OBJS += \
./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_float.o \
./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int16.o \
./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int32.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/signal/src/kiss_fft_wrappers/%.o tensorflow/signal/src/kiss_fft_wrappers/%.su tensorflow/signal/src/kiss_fft_wrappers/%.cyclo: ../tensorflow/signal/src/kiss_fft_wrappers/%.cc tensorflow/signal/src/kiss_fft_wrappers/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-signal-2f-src-2f-kiss_fft_wrappers

clean-tensorflow-2f-signal-2f-src-2f-kiss_fft_wrappers:
	-$(RM) ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_float.cyclo ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_float.d ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_float.o ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_float.su ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int16.cyclo ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int16.d ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int16.o ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int16.su ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int32.cyclo ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int32.d ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int32.o ./tensorflow/signal/src/kiss_fft_wrappers/kiss_fft_int32.su

.PHONY: clean-tensorflow-2f-signal-2f-src-2f-kiss_fft_wrappers

