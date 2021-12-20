cmake_minimum_required(VERSION 3.21)
project(Matrices_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Matrices_main
        BinaryTree.h
        main.cpp
        Pair.h
        Tests.h
        NODE.h)
