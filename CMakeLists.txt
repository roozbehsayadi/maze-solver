cmake_minimum_required(VERSION 3.0)

project(MazeSolver)

include_directories(include/)

set(SOURCES
        src/main.cpp src/sdl_handler.cpp src/exceptions/sdl_exception.cpp src/image.cpp src/maze_solver.cpp src/point.cpp include/exceptions/opencv_exception.h src/exceptions/opencv_exception.cpp)

find_package(SDL2 REQUIRED)
set(SDL2_LIBRARIES -lSDL2)

find_package(SDL2_image REQUIRED)
set(SDL2_IMAGE_LIBRARIES -lSDL2_image)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -O2")

add_executable(MazeSolver ${SOURCES})

target_link_libraries(MazeSolver ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

target_link_libraries(MazeSolver ${OpenCV_LIBS})
