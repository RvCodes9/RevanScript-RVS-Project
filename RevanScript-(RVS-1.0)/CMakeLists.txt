cmake_minimum_required(VERSION 3.10)

project(RevanScript-RVS C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(RevanScript ${SOURCES})

target_compile_options(RevanScript PRIVATE -O2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)