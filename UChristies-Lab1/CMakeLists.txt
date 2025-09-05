cmake_minimum_required(VERSION 3.10)

project(Gradable VERSION 1.0 DESCRIPTION "Gradable assets.")
include_directories("include/")
add_executable(Gradable uchristies.cpp gradable.cpp baseballcard.cpp coin.cpp)
target_compile_options(Gradable PRIVATE "-Wall")
