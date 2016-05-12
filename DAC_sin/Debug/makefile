################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
DAC_sin.lss \

FLASH_IMAGE += \
DAC_sin.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DAC_sin.elf secondary-outputs

# Tool invocations
DAC_sin.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DAC_sin.map -mmcu=atmega16 -o "DAC_sin.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DAC_sin.lss: DAC_sin.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DAC_sin.elf  >"DAC_sin.lss"
	@echo 'Finished building: $@'
	@echo ' '

DAC_sin.hex: DAC_sin.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DAC_sin.elf  "DAC_sin.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DAC_sin.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 DAC_sin.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DAC_sin.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
