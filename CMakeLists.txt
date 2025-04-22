cmake_minimum_required(VERSION 3.1)
project(sorting_algorithms)


set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    main.cpp
    sorting_algorithms/sorting.cpp
)

add_executable(sorting_algorithms ${SOURCES})
target_include_directories(sorting_algorithms PRIVATE ${CMAKE_SOURCE_DIR}/sorting_algorithms)
