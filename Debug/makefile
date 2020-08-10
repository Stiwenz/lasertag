################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lasertag_receiver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lasertag_receiver.list \

OBJCOPY_BIN += \
lasertag_receiver.bin \


# All Target
all: lasertag_receiver.elf secondary-outputs

# Tool invocations
lasertag_receiver.elf: $(OBJS) $(USER_OBJS) C:\projects\stm32_projects\lasertag_receiver\STM32F030F4PX_FLASH.ld
	arm-none-eabi-gcc -o "lasertag_receiver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\projects\stm32_projects\lasertag_receiver\STM32F030F4PX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lasertag_receiver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lasertag_receiver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lasertag_receiver.list"
	@echo 'Finished building: $@'
	@echo ' '

lasertag_receiver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lasertag_receiver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
