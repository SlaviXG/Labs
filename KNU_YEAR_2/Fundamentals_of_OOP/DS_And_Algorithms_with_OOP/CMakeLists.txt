cmake_minimum_required(VERSION 3.23)
project(DS_And_Algorithms_with_OOP)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
set(SOURCE_FILES main.cpp components/Tests.cpp)

add_executable(DS_And_Algorithms_with_OOP main.cpp components/SkipList.hpp components/SkipList.h components/UI.cpp components/UI.h components/Time.cpp components/Time.h)
add_executable(Tests components/SkipList.hpp components/SkipList.h components/UI.cpp components/UI.h components/Time.cpp components/Time.h components/Tests.cpp)

target_link_libraries(Tests gtest gtest_main)