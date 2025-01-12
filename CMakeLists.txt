cmake_minimum_required(VERSION 3.23)
project(Casino)
set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(casino casino.cpp)
