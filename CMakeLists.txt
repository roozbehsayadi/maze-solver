cmake_minimum_required(VERSION 3.0)

project(MazeSolver)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-Wall -O2")

add_executable(MazeSolver src/main.cpp)

target_link_libraries(MazeSolver ${OpenCV_LIBS})
