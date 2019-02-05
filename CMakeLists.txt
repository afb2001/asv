cmake_minimum_required(VERSION 3.13)
project(asv)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(dubins)
add_subdirectory(common)

#link_directories(dubins common) # ??

add_executable(asv main.cpp)
