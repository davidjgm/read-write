cmake_minimum_required(VERSION 3.16)
project(read_write)

set(CMAKE_CXX_STANDARD 14)

include_directories(include
        /usr/local/include/eigen3)

add_executable(read_write
    include/rw.h
    src/rw.cpp
    src/tests.cpp)
