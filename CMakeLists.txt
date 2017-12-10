cmake_minimum_required(VERSION 3.7)
project(final)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp HousePrice.cpp HousePrice.h
        HouseFunc.cpp HouseFunc.h)
add_executable(final ${SOURCE_FILES})