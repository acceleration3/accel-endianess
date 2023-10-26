cmake_minimum_required(VERSION 3.10)

project(accel-endianess CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

if(NOT DEFINED ACCEL_MODULES_FOLDER)
    set(ACCEL_MODULES_FOLDER "${CMAKE_SOURCE_DIR}/external")
endif()

include(cmake/FindModule.cmake)
add_accel_module(accel-macros)

set(ADDITIONAL_LIBRARIES accel-macros)
set(ADDITIONAL_DEFINITIONS "")

add_subdirectory(inspections)

add_library(accel-endianess INTERFACE)
target_include_directories(accel-endianess INTERFACE "include/")
target_compile_definitions(accel-endianess INTERFACE ${ADDITIONAL_DEFINITIONS})
target_link_libraries(accel-endianess INTERFACE ${ADDITIONAL_LIBRARIES})


if(ACCEL_BUILD_TESTS)
    add_subdirectory(tests)
endif()