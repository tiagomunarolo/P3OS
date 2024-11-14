# P3OS

P3OS is a project aimed at creating an operating system from scratch. It is designed for educational purposes to understand how OS components interact at the fundamental level, from bootstrapping the system to managing hardware and system resources. This project is written in **C** and **Assembly**, with the goal of building an OS that can boot on real hardware or in a virtualized environment.

## Table of Contents
- [Project Overview](#project-overview)
- [Requirements](#requirements)
- [Setup](#setup)
- [Building P3OS: Step-by-Step](#building-p3os-step-by-step)
  - [1. Bootloader](#1-bootloader)
  - [2. Kernel Initialization](#2-kernel-initialization)
  - [3. Memory Management](#3-memory-management)
  - [4. Task Scheduling](#4-task-scheduling)
  - [5. File System](#5-file-system)
  - [6. User Mode](#6-user-mode)
  - [7. Drivers and I/O](#7-drivers-and-io)
  - [8. Shell Interface](#8-shell-interface)
- [Debugging P3OS](#testing-p3os)
- [Contributing](#contributing)
- [License](#license)

## Project Overview

P3OS is being developed to explore the low-level components and structure of an operating system. This project covers essential OS topics such as bootloaders, kernel development, memory management, multitasking, and hardware abstraction. By the end of this project, P3OS aims to be a minimalistic OS capable of basic file management, task scheduling, and offering a shell interface.

## Requirements

- **Development Environment**: GCC, ASM (Netwide Assembler), QEMU (or Bochs) for emulation
- **Toolchain**: Cross-compiler setup for arm64
- **Additional Libraries**: gcc, binutils, ld, etc

To set up the cross-compiler, follow [this guide on OSDev](https://wiki.osdev.org/GCC_Cross-Compiler).

## Setup

1. Clone the repository:
   ```bash
   # Clone the repository
   git clone https://github.com/tiagomunarolo/P3OS.git
   # Ensure you are in the P3OS directory
   cd P3OS
   # Create build directory and run
   mkdir build && cd build && cmake ../ && make
   # Start Qemu Emulator
   qemu-system-aarch64 -M virt -kernel build/p3OS.elf -cpu cortex-a57 -m 128M -nographic
   ```
## Testing P3OS

```bash
  # 1: Init Qemu Emulator (First Shell):
  qemu-system-aarch64 -M virt -kernel build/p3OS.elf -cpu cortex-a57 -m 128M -nographic
  # 2: init GDB on bash terminal:
  gdb <local-path>/p3OS.elf
  # After start GDB, type:
  gdb>target remote localhost:1234
  # 3: run and debug:
  gdb> ... debug ...
  ```