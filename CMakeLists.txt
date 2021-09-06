cmake_minimum_required(VERSION 3.20)
project(HelloWorldClion)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        sort.h
        )

set(PROJECT_SOURCES
        main.cpp
        counting_sort.h binary_sort.h radix_sort.h)

add_executable(HelloWorldClion ${PROJECT_SOURCES} ${PROJECT_HEADERS})