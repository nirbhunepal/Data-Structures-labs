cmake_minimum_required(VERSION 3.10)


project(Gossip VERSION 1.0 DESCRIPTION "Let's Talk")
include_directories("include/")
add_executable(gossip gossip.cpp gossiper.cpp)
