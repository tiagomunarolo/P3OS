# kernel/CMakeLists.txt
target_sources(${target}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/uart.c
        ${CMAKE_CURRENT_SOURCE_DIR}/kernel.c
)

# include directories
target_include_directories(${target}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

# add subdirectories
add_subdirectory(arch/arm/arm64)