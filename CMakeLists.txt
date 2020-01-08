cmake_minimum_required(VERSION 3.15)
project(lab1_)

set(CMAKE_CXX_STANDARD 14)

add_library(
        lab1_shared SHARED
        library.h
        library.cpp)

add_executable(lab1 main.cpp )

target_link_libraries(lab1 PUBLIC lab1_shared)