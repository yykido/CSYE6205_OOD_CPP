cmake_minimum_required(VERSION 3.23)
project(HW1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW1
        p1.cpp
        p1.h
        p1test.cpp
        util.h)
