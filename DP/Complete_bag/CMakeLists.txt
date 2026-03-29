cmake_minimum_required(VERSION 3.28)
project(Complete_bag)

set(CMAKE_CXX_STANDARD 17)

add_executable(Complete_bag main.cpp
        opt.cpp
        opt_again.cpp)
