cmake_minimum_required(VERSION 3.20)
project(HelloWorldClion)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        counting_sort.h
        binary_sort.h
        radix_sort.h
        naive_search.h kmp_search.h breadth_first_search.h depth_first_search.h)

set(PROJECT_SOURCES
        main.cpp
        custom_aa_sort.h)

add_executable(HelloWorldClion ${PROJECT_SOURCES} ${PROJECT_HEADERS})