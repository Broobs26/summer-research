################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/signal/src/circular_buffer.cc \
../tensorflow/signal/src/energy.cc \
../tensorflow/signal/src/fft_auto_scale.cc \
../tensorflow/signal/src/filter_bank.cc \
../tensorflow/signal/src/filter_bank_log.cc \
../tensorflow/signal/src/filter_bank_spectral_subtraction.cc \
../tensorflow/signal/src/filter_bank_square_root.cc \
../tensorflow/signal/src/irfft_float.cc \
../tensorflow/signal/src/irfft_int16.cc \
../tensorflow/signal/src/irfft_int32.cc \
../tensorflow/signal/src/log.cc \
../tensorflow/signal/src/max_abs.cc \
../tensorflow/signal/src/msb_32.cc \
../tensorflow/signal/src/msb_64.cc \
../tensorflow/signal/src/overlap_add.cc \
../tensorflow/signal/src/rfft_float.cc \
../tensorflow/signal/src/rfft_int16.cc \
../tensorflow/signal/src/rfft_int32.cc \
../tensorflow/signal/src/square_root_32.cc \
../tensorflow/signal/src/square_root_64.cc \
../tensorflow/signal/src/window.cc 

CC_DEPS += \
./tensorflow/signal/src/circular_buffer.d \
./tensorflow/signal/src/energy.d \
./tensorflow/signal/src/fft_auto_scale.d \
./tensorflow/signal/src/filter_bank.d \
./tensorflow/signal/src/filter_bank_log.d \
./tensorflow/signal/src/filter_bank_spectral_subtraction.d \
./tensorflow/signal/src/filter_bank_square_root.d \
./tensorflow/signal/src/irfft_float.d \
./tensorflow/signal/src/irfft_int16.d \
./tensorflow/signal/src/irfft_int32.d \
./tensorflow/signal/src/log.d \
./tensorflow/signal/src/max_abs.d \
./tensorflow/signal/src/msb_32.d \
./tensorflow/signal/src/msb_64.d \
./tensorflow/signal/src/overlap_add.d \
./tensorflow/signal/src/rfft_float.d \
./tensorflow/signal/src/rfft_int16.d \
./tensorflow/signal/src/rfft_int32.d \
./tensorflow/signal/src/square_root_32.d \
./tensorflow/signal/src/square_root_64.d \
./tensorflow/signal/src/window.d 

OBJS += \
./tensorflow/signal/src/circular_buffer.o \
./tensorflow/signal/src/energy.o \
./tensorflow/signal/src/fft_auto_scale.o \
./tensorflow/signal/src/filter_bank.o \
./tensorflow/signal/src/filter_bank_log.o \
./tensorflow/signal/src/filter_bank_spectral_subtraction.o \
./tensorflow/signal/src/filter_bank_square_root.o \
./tensorflow/signal/src/irfft_float.o \
./tensorflow/signal/src/irfft_int16.o \
./tensorflow/signal/src/irfft_int32.o \
./tensorflow/signal/src/log.o \
./tensorflow/signal/src/max_abs.o \
./tensorflow/signal/src/msb_32.o \
./tensorflow/signal/src/msb_64.o \
./tensorflow/signal/src/overlap_add.o \
./tensorflow/signal/src/rfft_float.o \
./tensorflow/signal/src/rfft_int16.o \
./tensorflow/signal/src/rfft_int32.o \
./tensorflow/signal/src/square_root_32.o \
./tensorflow/signal/src/square_root_64.o \
./tensorflow/signal/src/window.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/signal/src/%.o tensorflow/signal/src/%.su tensorflow/signal/src/%.cyclo: ../tensorflow/signal/src/%.cc tensorflow/signal/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-signal-2f-src

clean-tensorflow-2f-signal-2f-src:
	-$(RM) ./tensorflow/signal/src/circular_buffer.cyclo ./tensorflow/signal/src/circular_buffer.d ./tensorflow/signal/src/circular_buffer.o ./tensorflow/signal/src/circular_buffer.su ./tensorflow/signal/src/energy.cyclo ./tensorflow/signal/src/energy.d ./tensorflow/signal/src/energy.o ./tensorflow/signal/src/energy.su ./tensorflow/signal/src/fft_auto_scale.cyclo ./tensorflow/signal/src/fft_auto_scale.d ./tensorflow/signal/src/fft_auto_scale.o ./tensorflow/signal/src/fft_auto_scale.su ./tensorflow/signal/src/filter_bank.cyclo ./tensorflow/signal/src/filter_bank.d ./tensorflow/signal/src/filter_bank.o ./tensorflow/signal/src/filter_bank.su ./tensorflow/signal/src/filter_bank_log.cyclo ./tensorflow/signal/src/filter_bank_log.d ./tensorflow/signal/src/filter_bank_log.o ./tensorflow/signal/src/filter_bank_log.su ./tensorflow/signal/src/filter_bank_spectral_subtraction.cyclo ./tensorflow/signal/src/filter_bank_spectral_subtraction.d ./tensorflow/signal/src/filter_bank_spectral_subtraction.o ./tensorflow/signal/src/filter_bank_spectral_subtraction.su ./tensorflow/signal/src/filter_bank_square_root.cyclo ./tensorflow/signal/src/filter_bank_square_root.d ./tensorflow/signal/src/filter_bank_square_root.o ./tensorflow/signal/src/filter_bank_square_root.su ./tensorflow/signal/src/irfft_float.cyclo ./tensorflow/signal/src/irfft_float.d ./tensorflow/signal/src/irfft_float.o ./tensorflow/signal/src/irfft_float.su ./tensorflow/signal/src/irfft_int16.cyclo ./tensorflow/signal/src/irfft_int16.d ./tensorflow/signal/src/irfft_int16.o ./tensorflow/signal/src/irfft_int16.su ./tensorflow/signal/src/irfft_int32.cyclo ./tensorflow/signal/src/irfft_int32.d ./tensorflow/signal/src/irfft_int32.o ./tensorflow/signal/src/irfft_int32.su ./tensorflow/signal/src/log.cyclo ./tensorflow/signal/src/log.d ./tensorflow/signal/src/log.o ./tensorflow/signal/src/log.su ./tensorflow/signal/src/max_abs.cyclo ./tensorflow/signal/src/max_abs.d ./tensorflow/signal/src/max_abs.o ./tensorflow/signal/src/max_abs.su ./tensorflow/signal/src/msb_32.cyclo ./tensorflow/signal/src/msb_32.d ./tensorflow/signal/src/msb_32.o ./tensorflow/signal/src/msb_32.su ./tensorflow/signal/src/msb_64.cyclo ./tensorflow/signal/src/msb_64.d ./tensorflow/signal/src/msb_64.o ./tensorflow/signal/src/msb_64.su ./tensorflow/signal/src/overlap_add.cyclo ./tensorflow/signal/src/overlap_add.d ./tensorflow/signal/src/overlap_add.o ./tensorflow/signal/src/overlap_add.su ./tensorflow/signal/src/rfft_float.cyclo ./tensorflow/signal/src/rfft_float.d ./tensorflow/signal/src/rfft_float.o ./tensorflow/signal/src/rfft_float.su ./tensorflow/signal/src/rfft_int16.cyclo ./tensorflow/signal/src/rfft_int16.d ./tensorflow/signal/src/rfft_int16.o ./tensorflow/signal/src/rfft_int16.su ./tensorflow/signal/src/rfft_int32.cyclo ./tensorflow/signal/src/rfft_int32.d ./tensorflow/signal/src/rfft_int32.o ./tensorflow/signal/src/rfft_int32.su ./tensorflow/signal/src/square_root_32.cyclo ./tensorflow/signal/src/square_root_32.d ./tensorflow/signal/src/square_root_32.o ./tensorflow/signal/src/square_root_32.su ./tensorflow/signal/src/square_root_64.cyclo ./tensorflow/signal/src/square_root_64.d ./tensorflow/signal/src/square_root_64.o ./tensorflow/signal/src/square_root_64.su ./tensorflow/signal/src/window.cyclo ./tensorflow/signal/src/window.d ./tensorflow/signal/src/window.o ./tensorflow/signal/src/window.su

.PHONY: clean-tensorflow-2f-signal-2f-src

