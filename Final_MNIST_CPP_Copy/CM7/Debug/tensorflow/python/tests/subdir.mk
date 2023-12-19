################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow/python/tests/cc_deps_link_test.cc 

CC_DEPS += \
./tensorflow/python/tests/cc_deps_link_test.d 

OBJS += \
./tensorflow/python/tests/cc_deps_link_test.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow/python/tests/%.o tensorflow/python/tests/%.su tensorflow/python/tests/%.cyclo: ../tensorflow/python/tests/%.cc tensorflow/python/tests/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++17 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H747xx -c -I../Core/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../Drivers/BSP/Components/Common -I../Drivers/BSP/STM32H747I-DISCO -I../Utilites/CPU -I../Utilites/Fonts -I../Utilites/lcd -I../tensorflow -I../tensorflow/third_party/ -I../tensorflow/third_party/gemmlowp -I../tensorflow/third_party/ruy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow-2f-python-2f-tests

clean-tensorflow-2f-python-2f-tests:
	-$(RM) ./tensorflow/python/tests/cc_deps_link_test.cyclo ./tensorflow/python/tests/cc_deps_link_test.d ./tensorflow/python/tests/cc_deps_link_test.o ./tensorflow/python/tests/cc_deps_link_test.su

.PHONY: clean-tensorflow-2f-python-2f-tests

