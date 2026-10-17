
cmake_minimum_required(VERSION 3.10)
project(MoonLanders)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(lander src/body.cpp src/lander.cpp src/main.cpp src/priorityQ.cpp)

target_include_directories(lander PRIVATE include)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
