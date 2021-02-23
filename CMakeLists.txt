cmake_minimum_required(VERSION 3.17)
project(containers)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -std=c++98")

include_directories(.)
include_directories(List Utils)

add_executable(containers List/List.hpp List/ListNode.hpp List/ListIterator.hpp listTest.cpp)
