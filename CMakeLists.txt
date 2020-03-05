cmake_minimum_required(VERSION 3.15)
project(BFS)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(BFS src/main.cpp src/BFS.cpp)

include_directories(include ${OpenCV_INCLUDE_DIRS})

target_link_libraries (BFS ${OpenCV_LIBS})