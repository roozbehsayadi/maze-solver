cmake_minimum_required(VERSION 3.0)

project(MazeSolver)

include_directories(include)

set(SOURCES
        src/main.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Wall -O2")

add_executable(MazeSolver ${SOURCES})

target_link_libraries(MazeSolver ${OpenCV_LIBS})
