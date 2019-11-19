cmake_minimum_required (VERSION 3.5)
#project name
project(lab5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
set(SOURCES src/main.cpp 
            src/stock.cpp
            src/stockNode.cpp
            src/stockSinglyLL.cpp
            src/consoleLL.cpp
            )


add_executable(lab5 ${SOURCES})
