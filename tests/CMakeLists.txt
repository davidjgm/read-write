cmake_minimum_required(VERSION 3.16)
project(hello_tests)

set(CMAKE_CXX_STANDARD 14)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE rw_lib)

