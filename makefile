# Define Compiler and Linker

# Assembler
ASM = as
ASM_FLAGS =

# Main Directories
BOOT_ROOT = ./bootloader
KERNEL_ROOT = ./kernel

# CC Compiler and Flags
CC = gcc
CC_FLAGS = -ffreestanding

# ASM Source Files
ASM_SRC = $(BOOT_ROOT)/boot.S
ASM_O = $(ASM_SRC:.S=.o)  # Convert .S files to .o files

# List of C source files
INCLUDES = $(KERNEL_ROOT)/includes
C_FILES = $(KERNEL_ROOT)/kernel.c  \
		$(KERNEL_ROOT)/uart.c
C_OBJ = $(C_FILES:.c=.o)  # Convert .c files to .o files

# Final executable target
TARGET = kernel.elf  

# Linker
LD = ld
LD_FLAGS =-T linker.ld

# QEMU flags
QEMU = qemu-system-aarch64 # QEMU executable for ARM64
QEMU_FLAGS = -machine virt -m 128M -cpu cortex-a57 -kernel $(TARGET) -nographic -s -S

# Default target: clean build and run the bootloader
all: clean run

# Clean up generated files
clean:
	@echo -e "Cleaning up object/elf files\n"
	@find . -type f -name "*.o" -print0 | xargs -0 rm -f
	@find . -type f -name "*.elf" -print0 | xargs -0 rm -f

	
# Run the bootloader in QEMU (can also be done using the 'all' target)
run: $(TARGET)
	$(QEMU) $(QEMU_FLAGS)


# Linking kernel and bootloader object files into the final executable
$(TARGET): $(ASM_O) $(C_OBJ)
	@echo -e "Linking kernel and bootloader into $(TARGET)\n"
	@$(LD) $(LD_FLAGS) -o $(TARGET) $(C_OBJ)


# Rule to compile bootloader (assembly) file
%.o:%.S
	@echo -e "Building $< ===> $@.\n"
	@$(ASM) $(ASM_FLAGS) $< -o $@


# Rule to compile .c files into .o files
%.o: %.c
	@echo -e "Building $< ===> $@.\n"
	@$(CC) $(CC_FLAGS) -c $< -o $@ -I $(INCLUDES)

# Help message
help:
	@echo "Makefile for building and running a simple ARM64 bootloader with NASM and QEMU."
	@echo "Targets:"
	@echo "  all      - Build and run the bootloader."
	@echo "  clean    - Remove the generated bootloader file."
	@echo "  run      - Run the bootloader in QEMU without rebuilding."
	@echo "  help     - Display this help message."
