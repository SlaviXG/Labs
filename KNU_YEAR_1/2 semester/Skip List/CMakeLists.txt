cmake_minimum_required(VERSION 3.20)
project(Skip_List)

set(CMAKE_CXX_STANDARD 20)

add_executable(Skip_List main.cpp Application.cpp Application.h Timer.cpp Timer.h SkipList.cpp SkipList.h)
