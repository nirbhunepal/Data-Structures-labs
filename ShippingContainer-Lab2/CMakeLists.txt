cmake_minimum_required(VERSION 3.10)

include_directories("include/")
project(teu VERSION 1.0 DESCRIPTION "Shipping Containers (Lab 2)")
add_executable(teu main.cpp)
set_property(TARGET teu PROPERTY CXX_STANDARD 20)
set_property(TARGET teu PROPERTY EXPORT_COMPILE_COMMANDS On)

find_package(Doxygen)

if (Doxygen_FOUND)
doxygen_add_docs(teu-docs include/teu/teu.hpp)
endif()
