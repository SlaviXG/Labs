cmake_minimum_required(VERSION 3.20)
project(17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(17 main.cpp)

set(SFML_DIR "S:\\Programs\\CLion\\SFML\\lib\\cmake\\SFML")

target_link_libraries(17 sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)
