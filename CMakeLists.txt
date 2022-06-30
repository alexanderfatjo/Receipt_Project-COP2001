cmake_minimum_required(VERSION 3.22)
project(Receipt_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Receipt_Project
        header.h
        main.cpp)
