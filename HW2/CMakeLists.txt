cmake_minimum_required(VERSION 3.23)
project(HW2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW2
        array.cpp
        array.h
        arraytest.cpp
        util.h)

#add_executable(HW2 main.cpp)
