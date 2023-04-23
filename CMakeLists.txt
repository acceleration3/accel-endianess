cmake_minimum_required(VERSION 3.10)

project(accel-endianness CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

if(NOT DEFINED ACCEL_MODULES_FOLDER)
    set(ACCEL_MODULES_FOLDER "${CMAKE_SOURCE_DIR}/external")
endif()

set(ADDITIONAL_DEFINITIONS "")

add_subdirectory(inspections)

add_library(accel-endianness INTERFACE)
target_include_directories(accel-endianness INTERFACE "include/")
target_compile_definitions(accel-endianness INTERFACE ${ADDITIONAL_DEFINITIONS})

if(ACCEL_BUILD_TESTS)
    add_subdirectory(tests)
endif()