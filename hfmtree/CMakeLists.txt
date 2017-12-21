cmake_minimum_required(VERSION 3.9)
project(hfmtree)

set(CMAKE_CXX_STANDARD 11)

add_executable(hfmtree main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")