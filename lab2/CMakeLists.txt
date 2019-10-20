cmake_minimum_required (VERSION 3.5)
#project name
project(lab2)

include_directories("${PROJECT_SOURCE_DIR}/include")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
set(SOURCES src/main.cpp src/complexNumber.cpp include/utils.hpp)


add_executable(lab2 ${SOURCES})