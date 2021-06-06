cmake_minimum_required(VERSION 3.0)
project(cpptest CXX)

# Build options
option(DEBUG_BUILD "Build software using debug configuration" ON)

# Source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Output files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/_out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/_out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/_out/bin)

# cpptest as a library
add_library(cpptest SHARED ${SOURCES})

# Compiler flags
add_compile_definitions(RELEASE=0 DEBUG=1)
if(DEBUG_BUILD)
    message(STATUS "Build type is DEBUG")
    add_compile_options(-Og -g -std=c++11 -Wall -Wextra -Werror -DBUILD_TYPE=DEBUG)
else()
message(STATUS "Build type is RELEASE")
    add_compile_options(-O3 -std=c++11 -Wall -Wextra -Werror -DBUILD_TYPE=RELEASE)
endif()

# Examples
add_subdirectory(examples)
