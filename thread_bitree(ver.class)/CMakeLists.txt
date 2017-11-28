cmake_minimum_required(VERSION 3.9)
project(thread_bitree_ver_class_)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp class/btnode.cpp class/btnode.h)
add_executable(thread_bitree_ver_class_ ${SOURCE_FILES})