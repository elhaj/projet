################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../EntityManager.cpp \
../ISQLAttribute.cpp \
../ISQLDataClass.cpp \
../ISQLDataStore.cpp \
../ISQLEntity.cpp \
../ISQLResultSet.cpp \
../ISQLRow.cpp \
../MySQLDataStore.cpp \
../MySQLEntity.cpp \
../MySQLEntityCollection.cpp \
../SQLSession.cpp \
../main.cpp 

OBJS += \
./EntityManager.o \
./ISQLAttribute.o \
./ISQLDataClass.o \
./ISQLDataStore.o \
./ISQLEntity.o \
./ISQLResultSet.o \
./ISQLRow.o \
./MySQLDataStore.o \
./MySQLEntity.o \
./MySQLEntityCollection.o \
./SQLSession.o \
./main.o 

CPP_DEPS += \
./EntityManager.d \
./ISQLAttribute.d \
./ISQLDataClass.d \
./ISQLDataStore.d \
./ISQLEntity.d \
./ISQLResultSet.d \
./ISQLRow.d \
./MySQLDataStore.d \
./MySQLEntity.d \
./MySQLEntityCollection.d \
./SQLSession.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.8.2\include\c++" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.8.2\include\c++\x86_64-pc-cygwin" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.8.2\include\c++\backward" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.8.2\include" -I"C:\cygwin64\lib\gcc\x86_64-pc-cygwin\4.8.2\include-fixed" -I"C:\cygwin64\usr\include" -I"C:\cygwin64\usr\include\w32api" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


