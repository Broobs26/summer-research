################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/TF/debug_log.c 

CPP_SRCS += \
../Core/Src/TF/main_functions1.cpp \
../Core/Src/TF/model_chunk1.cpp \
../Core/Src/TF/model_chunk2.cpp \
../Core/Src/TF/model_chunk3.cpp 

C_DEPS += \
./Core/Src/TF/debug_log.d 

OBJS += \
./Core/Src/TF/debug_log.o \
./Core/Src/TF/main_functions1.o \
./Core/Src/TF/model_chunk1.o \
./Core/Src/TF/model_chunk2.o \
./Core/Src/TF/model_chunk3.o 

CPP_DEPS += \
./Core/Src/TF/main_functions1.d \
./Core/Src/TF/model_chunk1.d \
./Core/Src/TF/model_chunk2.d \
./Core/Src/TF/model_chunk3.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/TF/%.o Core/Src/TF/%.su Core/Src/TF/%.cyclo: ../Core/Src/TF/%.c Core/Src/TF/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DCORE_CM4 -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../tensorflow -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -I../Hardware/ArduCAM -I../Hardware/I2C -I../Hardware/SPI -I../System/delay -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/TF/%.o Core/Src/TF/%.su Core/Src/TF/%.cyclo: ../Core/Src/TF/%.cpp Core/Src/TF/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -DCORE_CM4 -DARM_MATH_CM4 -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../tensorflow -I../third_party -I../third_party/flatbuffers/include -I../third_party/ruy -I../third_party/gemmlowp -I../Models -I../Hardware/ArduCAM -I../Hardware/I2C -I../Hardware/SPI -I../System/delay -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-TF

clean-Core-2f-Src-2f-TF:
	-$(RM) ./Core/Src/TF/debug_log.cyclo ./Core/Src/TF/debug_log.d ./Core/Src/TF/debug_log.o ./Core/Src/TF/debug_log.su ./Core/Src/TF/main_functions1.cyclo ./Core/Src/TF/main_functions1.d ./Core/Src/TF/main_functions1.o ./Core/Src/TF/main_functions1.su ./Core/Src/TF/model_chunk1.cyclo ./Core/Src/TF/model_chunk1.d ./Core/Src/TF/model_chunk1.o ./Core/Src/TF/model_chunk1.su ./Core/Src/TF/model_chunk2.cyclo ./Core/Src/TF/model_chunk2.d ./Core/Src/TF/model_chunk2.o ./Core/Src/TF/model_chunk2.su ./Core/Src/TF/model_chunk3.cyclo ./Core/Src/TF/model_chunk3.d ./Core/Src/TF/model_chunk3.o ./Core/Src/TF/model_chunk3.su

.PHONY: clean-Core-2f-Src-2f-TF

