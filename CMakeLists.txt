# Minimum required version of CMake
cmake_minimum_required(VERSION 3.22)

# Project name
project(sr04t)

set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_SYSTEM_PROCESSOR arm)


# Set msp-gcc for c files
set(CMAKE_C_COMPILER $ENV{HOME}/Tools/gcc-arm/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER $ENV{HOME}/Tools/gcc-arm/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-g++)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}_appl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}_lib.c
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/startup.c
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/stm32l0xx_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/system_stm32l0xx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/stm32l0xx_hal_msp.c
)

# Include directories
include_directories(
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

# Compiler flags
set(CMAKE_C_FLAGS "-mcpu=cortex-m0plus -nostartfiles -O2 -g -Wall -std=c11 -Wl,-Map=output.map")

# Linker flags
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker/linker.ld")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/STM32L0xx_HAL_ST stm32l0xx_hal_st)

# add_executable(Libraries src/library.c)
add_executable(${PROJECT_NAME}_appl.out ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}_appl.c)
target_link_libraries(${PROJECT_NAME}_appl.out 
                        stm32l0xx_hal_st
)
