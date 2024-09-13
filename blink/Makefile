# Makefile for compiling

CC := arm-none-eabi-gcc
MACH := cortex-m3 # SAM3X8E (Arduino Due) has ARM Cortex M3

# Important Directories
SRC_DIR := ./src
INC_DIR := ./include
OUT_DIR := ./output

# GCC Options
CFLAGS := -mcpu=$(MACH) -O0 -Wall -I$(INC_DIR)

# list of all .c files in src/
SRCES := $(wildcard $(SRC_DIR)/*.c)
# list of all .h files in inc/
INCS := $(wildcard $(INC_DIR)/*.h)
# list of all .o to be made from .c files
# substitute the ./src to ./output directory
OBJS := $(subst $(SRC_DIR),$(OUT_DIR),$(SRCES))
# replace .c to .o
OBJS := $(patsubst %.c,%.o,$(OBJS))

# Create the output folder and
# create .o files from all .c files in src
$(OBJS): $(SRCES) $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

# Remove everything in the output folder
clean:
	rm -r $(OUT_DIR)/*