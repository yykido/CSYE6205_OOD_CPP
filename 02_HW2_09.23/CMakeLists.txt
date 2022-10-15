cmake_minimum_required(VERSION 3.23)
project(02_HW2_09_23)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(02_HW2_09_23
                array.cpp
                arraytest.cpp
                array.h
                util.h)
