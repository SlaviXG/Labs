cmake_minimum_required(VERSION 3.23)
project(Master_Slave_micro_RDMS)

set(CMAKE_CXX_STANDARD 20)

add_executable(Master_Slave_micro_RDMS main.cpp components/UI.cpp components/UI.h)
