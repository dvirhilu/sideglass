# Makefile for compiling

# Variable Declarations
CC := arm-none-eabi-gcc
MACH := cortex-m3 # SAM3X8E (Arduino Due) has ARM Cortex M3
CFLAGS := -c -mcpu=$(MACH) -O0 -Wall

SRC_DIR := ./src
INC_DIR := ./include

SRCES := $(wildcard $(SRC_DIR)/*.c)
#SRCES := $(foreach $(SRC_DIR) -name '*.c')
INCS := $(wildcard $(INC_DIR)/*.h)

print: 
	echo $(SRCES)

#blink.o: blink.c
#	$(CC) $(CFLAGS) $^ -o $@