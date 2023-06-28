cmake_minimum_required(VERSION 3.15.3)
project(TopCommonWords)

set(CMAKE_CXX_STANDARD 14)

add_executable(TopCommonWords main.cpp counting.cpp cleaning.cpp)
