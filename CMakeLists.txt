cmake_minimum_required(VERSION 3.10)

project(RayTracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

add_subdirectory(core)
add_subdirectory(exercises)
add_subdirectory(light)
add_subdirectory(math)
add_subdirectory(shapes)
add_subdirectory(utils)
add_subdirectory(writer)