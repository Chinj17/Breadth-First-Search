cmake_minimum_required(VERSION 3.15)
project(BFS)

set(CMAKE_CXX_STANDARD 14)

add_executable(BFS src/main.cpp src/BFS.cpp)

include_directories(include)
