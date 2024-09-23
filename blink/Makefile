# Makefile for compiling

CC   := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
PROG := bossac 
MACH := cortex-m3 # SAM3X8E (Arduino Due) has ARM Cortex M3

# Important Directories
SRC_DIR := ./src
INC_DIR := ./include
OUT_DIR := ./output

# GCC Options
CFLAGS := -mcpu=$(MACH) -O0 -Wall -I$(INC_DIR)
# Also create .map file to view .elf's information TODO: Modify flag if using stdlib
LFLAGS = -nostdlib -T $(LINKER) -Wl,-Map=$(OUT_DIR)/blink.map

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
FNAMES := $(patsubst %.c,%,$(SRCS))
# Remove the directory part
FNAMES := $(patsubst $(SRC_DIR)/%,%,$(FNAMES))

# "all" target to compile all files
all: $(FNAMES) link bin

# Create the output folder and
# Create object files (.o) for each source file (.c)
$(FNAMES): $(SRCS) $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $(OUT_DIR)/$@.o $(SRC_DIR)/$@.c 

# Link object (.o) files
link: $(OBJS) $(LINKER)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUTFILE)

bin: $(OUTFILE)
	$(OBJCOPY) -O binary $(OUTFILE) $(OUT_DIR)/blink.bin

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
	$(PROG) -U true -p $(PORT) -e -w -v -b -i -R $(OUTFILE)