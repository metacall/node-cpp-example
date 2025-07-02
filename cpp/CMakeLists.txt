cmake_minimum_required(VERSION 3.10)
project(TestLibrary)

# Build test shared library
add_library(test SHARED test.cpp)
