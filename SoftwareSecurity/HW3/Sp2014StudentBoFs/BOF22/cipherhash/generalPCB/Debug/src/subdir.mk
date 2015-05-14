################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/datastruture.c \
../src/generalPCB.c \
../src/menu.c \
../src/pcbhandler.c \
../src/test.c \
../src/utility.c 

OBJS += \
./src/datastruture.o \
./src/generalPCB.o \
./src/menu.o \
./src/pcbhandler.o \
./src/test.o \
./src/utility.o 

C_DEPS += \
./src/datastruture.d \
./src/generalPCB.d \
./src/menu.d \
./src/pcbhandler.d \
./src/test.d \
./src/utility.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I"/home/hilberttaylor/workspace/generalPCB/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


