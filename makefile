# Define Compiler and Linker

# Assembler
ASM = as
ASM_FLAGS =

BOOT_ROOT = ./bootloader
KERNEL_ROOT = ./kernel
TARGET = ./target

# Compiler
CC = gcc
CC_FLAGS = -ffreestanding

# Source Files
SRC = $(BOOT_ROOT)/boot.S  # source file
LINKER_LD = linker.ld
# Output Files
BOOT_O = $(TARGET)/boot.o  # temporary object file
KERNEL_O = $(TARGET)/kernel.o
KERNEL_ELF = $(TARGET)/kernel.elf
KERNEL_BIN = $(TARGET)/kernel.bin

# Definer QEMU flags
QEMU = qemu-system-aarch64 # QEMU executable for ARM64
QEMU_FLAGS = -machine virt -cpu cortex-a57 -kernel $(KERNEL_ELF) -nographic -s -S

# Linker
LD = ld
LD_FLAGS = -T$(LINKER_LD)

# Default target: Build and run the bootloader
all: clean link_kernel

$(TARGET):
	@echo "Creating target directory: $(TARGET)"
	@mkdir -p $(TARGET)


$(KERNEL_O): $(TARGET)
	@echo "Building kernel.c file: $(KERNEL_O)"
	$(CC) $(CC_FLAGS) -c $(KERNEL_ROOT)/kernel.c -o $(KERNEL_O)

$(BOOT_O): $(TARGET)
	@echo "Building boot.asm file: $(BOOT_O)"
	$(ASM) $(ASM_FLAGS) $(SRC) -o $(BOOT_O)

# Build the bootloader: kernel.c, and boot.asm
link_kernel: $(BOOT_O) $(KERNEL_O)
	$(LD) $(LD_FLAGS) -o $(KERNEL_ELF) $(KERNEL_O)

# Clean up generated files
clean:
	rm -rf $(TARGET)
	@echo "Cleaned up."

# Run the bootloader in QEMU (can also be done using the 'all' target)
run: kernel
	$(QEMU) $(QEMU_FLAGS)

# Help message
help:
	@echo "Makefile for building and running a simple ARM64 bootloader with NASM and QEMU."
	@echo "Targets:"
	@echo "  all      - Build and run the bootloader."
	@echo "  clean    - Remove the generated bootloader file."
	@echo "  run      - Run the bootloader in QEMU without rebuilding."
	@echo "  help     - Display this help message."