cmake_minimum_required(VERSION 3.10)

project(RayTracer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

add_subdirectory(core)
add_subdirectory(exercises)