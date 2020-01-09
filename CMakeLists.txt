cmake_minimum_required(VERSION 3.15)
project(lib_1_SVEmelyanenko)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(
        _1_SVEmelyanenko_Euler SHARED
        lib_1_SVEmelyanenko_Euler/lib_1_SVEmelyanenko_Euler.h
        lib_1_SVEmelyanenko_Euler/lib_1_SVEmelyanenko_Euler.cpp)

add_library(
        _1_SVEmelyanenko_Huhne SHARED
        lib_1_SVEmelyanenko_Huhne/lib_1_SVEmelyanenko_Huhne.h
        lib_1_SVEmelyanenko_Huhne/lib_1_SVEmelyanenko_Huhne.cpp)

add_executable(lab1
        prj_1_SVEmelyanenko_Host/prj_1_SVEmelyanenko_Host.cpp
        prj_1_SVEmelyanenko_Host/Host.cpp
        prj_1_SVEmelyanenko_Host/Host.h)