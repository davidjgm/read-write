cmake_minimum_required(VERSION 3.16)
project(hello_prog)

set(CMAKE_CXX_STANDARD 14)
# All sources that also need to be tested in unit tests go into a static library
add_library(rw_lib STATIC rw.cpp ../include/rw.h)
target_include_directories(rw_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ../include /usr/local/include/eigen3)
# Executable
#add_executable(prog main.cpp)
#target_link_libraries(prog PRIVATE rw_lib)