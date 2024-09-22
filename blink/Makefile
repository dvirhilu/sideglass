# Makefile for compiling

CC   := arm-none-eabi-gcc
PROG := bossac 
MACH := cortex-m3 # SAM3X8E (Arduino Due) has ARM Cortex M3

# Important Directories
SRC_DIR := ./src
INC_DIR := ./include
OUT_DIR := ./output

# GCC Options
CFLAGS := -mcpu=$(MACH) -O0 -Wall -I$(INC_DIR)

# List of all .c files in src/
SRCS := $(wildcard $(SRC_DIR)/*.c)
# List of all .h files in inc/
INCS := $(wildcard $(INC_DIR)/*.h)
# List of all .o to be made from .c files
# Substitute the ./src to ./output directory
OBJS := $(subst $(SRC_DIR),$(OUT_DIR),$(SRCS))
# Replace .c to .o
OBJS := $(patsubst %.c,%.o,$(OBJS))

# Linker script
LINKER := sam3x8e_linker.ld
# Output file name
OUTFILE := $(OUT_DIR)/blink.elf

# File names without directory or file extensions
# Remove the .c endings
FILENAME := $(patsubst %.c,%,$(SRCS))
# Remove the directory part
FILENAME := $(patsubst $(SRC_DIR)/%,%,$(FILENAME))

# "all" target to compile all files
all: $(FILENAME) link

# Create the output folder and
# Create object files (.o) for each source file (.c)
$(FILENAME): $(SRCS) $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $(OUT_DIR)/$@.o $(SRC_DIR)/$@.c 

# Link object (.o) files. TODO: Modify flag if using stdlib
link: $(OBJS) $(LINKER)
	$(CC) -nostdlib -T $(LINKER) $(OBJS) -o $(OUTFILE)

# Remove everything in the output folder
clean:
	rm -r $(OUT_DIR)/*

# Program binary file into device
# 	-e erase flash
# 	-w write binary to flash
# 	-v verify that the flash contents match binary
# 	-b set to boot from flash
# 	-i display diagnostic information identifying target device
# 	-R reset CPU after writing to target
prog:
	$(PROG) -e -w -v -b -i -R $(BIN_FILE)