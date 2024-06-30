# CMake.txt
# C Application
cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE Debug)    
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Algo C)
add_executable(app main.c)
