# setup cmake version
cmake_minimum_required(VERSION 3.30.5)  
# setup project name
project(P3OS)                           

# set gcc compiler
set(CMAKE_C_COMPILER    gcc)
set(CMAKE_CXX_COMPILER  g++)

# setup c++ standard
set(CMAKE_CXX_STANDARD 17)              
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# enable assembly
enable_language(ASM)

# set target
set(target p3OS.elf)

# define target elf file
add_executable(${target})

# set compile options
target_compile_options(${target} PRIVATE
    -Werror
    -ffreestanding
)


# set link options
set(linker_script ${CMAKE_SOURCE_DIR}/kernel/arch/arm/arm64/linker.ld)
target_link_options(${target} PRIVATE
    -nostdlib
    -nostdinc
    -nodefaultlibs
    -nostartfiles
    -T ${linker_script}
)

# add subdirectories
add_subdirectory(kernel)