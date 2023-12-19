################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/signal/micro/kernels/delay.cc \
../tensorflow/signal/micro/kernels/delay_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/delay_test.cc \
../tensorflow/signal/micro/kernels/energy.cc \
../tensorflow/signal/micro/kernels/energy_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/energy_test.cc \
../tensorflow/signal/micro/kernels/fft_auto_scale.cc \
../tensorflow/signal/micro/kernels/fft_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/fft_test.cc \
../tensorflow/signal/micro/kernels/filter_bank.cc \
../tensorflow/signal/micro/kernels/filter_bank_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/filter_bank_log.cc \
../tensorflow/signal/micro/kernels/filter_bank_log_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/filter_bank_log_test.cc \
../tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction.cc \
../tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_test.cc \
../tensorflow/signal/micro/kernels/filter_bank_square_root.cc \
../tensorflow/signal/micro/kernels/filter_bank_square_root_test.cc \
../tensorflow/signal/micro/kernels/filter_bank_test.cc \
../tensorflow/signal/micro/kernels/framer.cc \
../tensorflow/signal/micro/kernels/framer_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/framer_test.cc \
../tensorflow/signal/micro/kernels/irfft.cc \
../tensorflow/signal/micro/kernels/overlap_add.cc \
../tensorflow/signal/micro/kernels/overlap_add_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/overlap_add_test.cc \
../tensorflow/signal/micro/kernels/rfft.cc \
../tensorflow/signal/micro/kernels/stacker.cc \
../tensorflow/signal/micro/kernels/stacker_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/stacker_test.cc \
../tensorflow/signal/micro/kernels/window.cc \
../tensorflow/signal/micro/kernels/window_flexbuffers_generated_data.cc \
../tensorflow/signal/micro/kernels/window_test.cc 

CC_DEPS += \
./tensorflow/signal/micro/kernels/delay.d \
./tensorflow/signal/micro/kernels/delay_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/delay_test.d \
./tensorflow/signal/micro/kernels/energy.d \
./tensorflow/signal/micro/kernels/energy_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/energy_test.d \
./tensorflow/signal/micro/kernels/fft_auto_scale.d \
./tensorflow/signal/micro/kernels/fft_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/fft_test.d \
./tensorflow/signal/micro/kernels/filter_bank.d \
./tensorflow/signal/micro/kernels/filter_bank_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/filter_bank_log.d \
./tensorflow/signal/micro/kernels/filter_bank_log_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/filter_bank_log_test.d \
./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction.d \
./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_test.d \
./tensorflow/signal/micro/kernels/filter_bank_square_root.d \
./tensorflow/signal/micro/kernels/filter_bank_square_root_test.d \
./tensorflow/signal/micro/kernels/filter_bank_test.d \
./tensorflow/signal/micro/kernels/framer.d \
./tensorflow/signal/micro/kernels/framer_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/framer_test.d \
./tensorflow/signal/micro/kernels/irfft.d \
./tensorflow/signal/micro/kernels/overlap_add.d \
./tensorflow/signal/micro/kernels/overlap_add_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/overlap_add_test.d \
./tensorflow/signal/micro/kernels/rfft.d \
./tensorflow/signal/micro/kernels/stacker.d \
./tensorflow/signal/micro/kernels/stacker_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/stacker_test.d \
./tensorflow/signal/micro/kernels/window.d \
./tensorflow/signal/micro/kernels/window_flexbuffers_generated_data.d \
./tensorflow/signal/micro/kernels/window_test.d 

OBJS += \
./tensorflow/signal/micro/kernels/delay.o \
./tensorflow/signal/micro/kernels/delay_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/delay_test.o \
./tensorflow/signal/micro/kernels/energy.o \
./tensorflow/signal/micro/kernels/energy_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/energy_test.o \
./tensorflow/signal/micro/kernels/fft_auto_scale.o \
./tensorflow/signal/micro/kernels/fft_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/fft_test.o \
./tensorflow/signal/micro/kernels/filter_bank.o \
./tensorflow/signal/micro/kernels/filter_bank_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/filter_bank_log.o \
./tensorflow/signal/micro/kernels/filter_bank_log_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/filter_bank_log_test.o \
./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction.o \
./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_test.o \
./tensorflow/signal/micro/kernels/filter_bank_square_root.o \
./tensorflow/signal/micro/kernels/filter_bank_square_root_test.o \
./tensorflow/signal/micro/kernels/filter_bank_test.o \
./tensorflow/signal/micro/kernels/framer.o \
./tensorflow/signal/micro/kernels/framer_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/framer_test.o \
./tensorflow/signal/micro/kernels/irfft.o \
./tensorflow/signal/micro/kernels/overlap_add.o \
./tensorflow/signal/micro/kernels/overlap_add_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/overlap_add_test.o \
./tensorflow/signal/micro/kernels/rfft.o \
./tensorflow/signal/micro/kernels/stacker.o \
./tensorflow/signal/micro/kernels/stacker_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/stacker_test.o \
./tensorflow/signal/micro/kernels/window.o \
./tensorflow/signal/micro/kernels/window_flexbuffers_generated_data.o \
./tensorflow/signal/micro/kernels/window_test.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/signal/micro/kernels/%.o tensorflow/signal/micro/kernels/%.su tensorflow/signal/micro/kernels/%.cyclo: ../tensorflow/signal/micro/kernels/%.cc tensorflow/signal/micro/kernels/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-signal-2f-micro-2f-kernels

clean-tensorflow-2f-signal-2f-micro-2f-kernels:
	-$(RM) ./tensorflow/signal/micro/kernels/delay.cyclo ./tensorflow/signal/micro/kernels/delay.d ./tensorflow/signal/micro/kernels/delay.o ./tensorflow/signal/micro/kernels/delay.su ./tensorflow/signal/micro/kernels/delay_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/delay_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/delay_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/delay_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/delay_test.cyclo ./tensorflow/signal/micro/kernels/delay_test.d ./tensorflow/signal/micro/kernels/delay_test.o ./tensorflow/signal/micro/kernels/delay_test.su ./tensorflow/signal/micro/kernels/energy.cyclo ./tensorflow/signal/micro/kernels/energy.d ./tensorflow/signal/micro/kernels/energy.o ./tensorflow/signal/micro/kernels/energy.su ./tensorflow/signal/micro/kernels/energy_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/energy_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/energy_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/energy_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/energy_test.cyclo ./tensorflow/signal/micro/kernels/energy_test.d ./tensorflow/signal/micro/kernels/energy_test.o ./tensorflow/signal/micro/kernels/energy_test.su ./tensorflow/signal/micro/kernels/fft_auto_scale.cyclo ./tensorflow/signal/micro/kernels/fft_auto_scale.d ./tensorflow/signal/micro/kernels/fft_auto_scale.o ./tensorflow/signal/micro/kernels/fft_auto_scale.su ./tensorflow/signal/micro/kernels/fft_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/fft_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/fft_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/fft_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/fft_test.cyclo ./tensorflow/signal/micro/kernels/fft_test.d ./tensorflow/signal/micro/kernels/fft_test.o ./tensorflow/signal/micro/kernels/fft_test.su ./tensorflow/signal/micro/kernels/filter_bank.cyclo ./tensorflow/signal/micro/kernels/filter_bank.d ./tensorflow/signal/micro/kernels/filter_bank.o ./tensorflow/signal/micro/kernels/filter_bank.su ./tensorflow/signal/micro/kernels/filter_bank_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/filter_bank_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/filter_bank_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/filter_bank_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/filter_bank_log.cyclo ./tensorflow/signal/micro/kernels/filter_bank_log.d ./tensorflow/signal/micro/kernels/filter_bank_log.o ./tensorflow/signal/micro/kernels/filter_bank_log.su ./tensorflow/signal/micro/kernels/filter_bank_log_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/filter_bank_log_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/filter_bank_log_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/filter_bank_log_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/filter_bank_log_test.cyclo ./tensorflow/signal/micro/kernels/filter_bank_log_test.d ./tensorflow/signal/micro/kernels/filter_bank_log_test.o ./tensorflow/signal/micro/kernels/filter_bank_log_test.su ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction.cyclo ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction.d ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction.o ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction.su ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_test.cyclo ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_test.d ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_test.o ./tensorflow/signal/micro/kernels/filter_bank_spectral_subtraction_test.su ./tensorflow/signal/micro/kernels/filter_bank_square_root.cyclo ./tensorflow/signal/micro/kernels/filter_bank_square_root.d ./tensorflow/signal/micro/kernels/filter_bank_square_root.o ./tensorflow/signal/micro/kernels/filter_bank_square_root.su ./tensorflow/signal/micro/kernels/filter_bank_square_root_test.cyclo ./tensorflow/signal/micro/kernels/filter_bank_square_root_test.d ./tensorflow/signal/micro/kernels/filter_bank_square_root_test.o ./tensorflow/signal/micro/kernels/filter_bank_square_root_test.su ./tensorflow/signal/micro/kernels/filter_bank_test.cyclo ./tensorflow/signal/micro/kernels/filter_bank_test.d ./tensorflow/signal/micro/kernels/filter_bank_test.o ./tensorflow/signal/micro/kernels/filter_bank_test.su ./tensorflow/signal/micro/kernels/framer.cyclo ./tensorflow/signal/micro/kernels/framer.d ./tensorflow/signal/micro/kernels/framer.o ./tensorflow/signal/micro/kernels/framer.su ./tensorflow/signal/micro/kernels/framer_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/framer_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/framer_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/framer_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/framer_test.cyclo ./tensorflow/signal/micro/kernels/framer_test.d ./tensorflow/signal/micro/kernels/framer_test.o ./tensorflow/signal/micro/kernels/framer_test.su ./tensorflow/signal/micro/kernels/irfft.cyclo ./tensorflow/signal/micro/kernels/irfft.d ./tensorflow/signal/micro/kernels/irfft.o ./tensorflow/signal/micro/kernels/irfft.su ./tensorflow/signal/micro/kernels/overlap_add.cyclo ./tensorflow/signal/micro/kernels/overlap_add.d ./tensorflow/signal/micro/kernels/overlap_add.o ./tensorflow/signal/micro/kernels/overlap_add.su
	-$(RM) ./tensorflow/signal/micro/kernels/overlap_add_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/overlap_add_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/overlap_add_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/overlap_add_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/overlap_add_test.cyclo ./tensorflow/signal/micro/kernels/overlap_add_test.d ./tensorflow/signal/micro/kernels/overlap_add_test.o ./tensorflow/signal/micro/kernels/overlap_add_test.su ./tensorflow/signal/micro/kernels/rfft.cyclo ./tensorflow/signal/micro/kernels/rfft.d ./tensorflow/signal/micro/kernels/rfft.o ./tensorflow/signal/micro/kernels/rfft.su ./tensorflow/signal/micro/kernels/stacker.cyclo ./tensorflow/signal/micro/kernels/stacker.d ./tensorflow/signal/micro/kernels/stacker.o ./tensorflow/signal/micro/kernels/stacker.su ./tensorflow/signal/micro/kernels/stacker_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/stacker_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/stacker_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/stacker_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/stacker_test.cyclo ./tensorflow/signal/micro/kernels/stacker_test.d ./tensorflow/signal/micro/kernels/stacker_test.o ./tensorflow/signal/micro/kernels/stacker_test.su ./tensorflow/signal/micro/kernels/window.cyclo ./tensorflow/signal/micro/kernels/window.d ./tensorflow/signal/micro/kernels/window.o ./tensorflow/signal/micro/kernels/window.su ./tensorflow/signal/micro/kernels/window_flexbuffers_generated_data.cyclo ./tensorflow/signal/micro/kernels/window_flexbuffers_generated_data.d ./tensorflow/signal/micro/kernels/window_flexbuffers_generated_data.o ./tensorflow/signal/micro/kernels/window_flexbuffers_generated_data.su ./tensorflow/signal/micro/kernels/window_test.cyclo ./tensorflow/signal/micro/kernels/window_test.d ./tensorflow/signal/micro/kernels/window_test.o ./tensorflow/signal/micro/kernels/window_test.su

.PHONY: clean-tensorflow-2f-signal-2f-micro-2f-kernels

