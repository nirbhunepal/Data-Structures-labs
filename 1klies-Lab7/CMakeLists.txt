cmake_minimum_required(VERSION 3.10)

project(1kLies VERSION 1.0 DESCRIPTION "A graph is worth a thousand lies.")
include_directories("include/")
add_executable(1klies 1klies.cpp)
add_executable(1klies_grinder 1klies_grinder.cpp)
set_property(TARGET 1klies PROPERTY CXX_STANDARD 17)
set_property(TARGET 1klies_grinder PROPERTY CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
