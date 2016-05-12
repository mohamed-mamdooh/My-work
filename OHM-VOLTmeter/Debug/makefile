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
OHM-VOLTmeter.lss \

FLASH_IMAGE += \
OHM-VOLTmeter.hex \

EEPROM_IMAGE += \
OHM-VOLTmeter.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: OHM-VOLTmeter.elf secondary-outputs

# Tool invocations
OHM-VOLTmeter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,OHM-VOLTmeter.map -mmcu=atmega16 -o "OHM-VOLTmeter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

OHM-VOLTmeter.lss: OHM-VOLTmeter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S OHM-VOLTmeter.elf  >"OHM-VOLTmeter.lss"
	@echo 'Finished building: $@'
	@echo ' '

OHM-VOLTmeter.hex: OHM-VOLTmeter.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex OHM-VOLTmeter.elf  "OHM-VOLTmeter.hex"
	@echo 'Finished building: $@'
	@echo ' '

OHM-VOLTmeter.eep: OHM-VOLTmeter.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex OHM-VOLTmeter.elf  "OHM-VOLTmeter.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: OHM-VOLTmeter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 OHM-VOLTmeter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) OHM-VOLTmeter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
