cmake_minimum_required(VERSION 3.10)


project(OrderSheWrote VERSION 1.0 DESCRIPTION "Calculate Shipping For Orders")
include_directories("include/")
add_executable(ordershewrote main.cpp order.cpp item.cpp)
