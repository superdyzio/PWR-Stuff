################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/graphic.c" \
"../Sources/main.c" \
"../Sources/t6963c.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/graphic.c \
../Sources/main.c \
../Sources/t6963c.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/graphic_c.obj \
./Sources/main_c.obj \
./Sources/t6963c_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/graphic_c.obj" \
"./Sources/main_c.obj" \
"./Sources/t6963c_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/graphic_c.d \
./Sources/main_c.d \
./Sources/t6963c_c.d \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/graphic_c.d" \
"./Sources/main_c.d" \
"./Sources/t6963c_c.d" \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/graphic_c.obj \
./Sources/main_c.obj \
./Sources/t6963c_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/Events.args" -o "Sources/Events_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/graphic_c.obj: ../Sources/graphic.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/graphic.args" -o "Sources/graphic_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/main.args" -o "Sources/main_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/t6963c_c.obj: ../Sources/t6963c.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"Sources/t6963c.args" -o "Sources/t6963c_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


