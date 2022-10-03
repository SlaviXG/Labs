cmake_minimum_required(VERSION 3.23)
project(DS_And_Algorithms_with_OOP)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)


add_executable(DS_And_Algorithms_with_OOP main.cpp components/SkipList.hpp components/SkipList.h components/UI.cpp components/UI.h components/Time.cpp components/Time.h)


target_link_libraries(DS_And_Algorithms_with_OOP gtest gtest_main)