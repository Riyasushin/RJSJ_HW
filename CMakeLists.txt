cmake_minimum_required(VERSION 3.10.0)
project(rjsj VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "CXX Compiler Flags: ${CMAKE_CXX_FLAGS}")

add_executable(rjsj notes/12/02.cpp)

