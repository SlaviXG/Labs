cmake_minimum_required(VERSION 3.23)
project(AC_Lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(AC_Lab1)

add_executable(AC_Lab1
        AC_Lab1/ComplexMatrix.h
        AC_Lab1/ComplexNum.h
        AC_Lab1/LU_Inverse.h
        AC_Lab1/Strassen.h
        AC_Lab1/doctest.h
        AC_Lab1/test.cpp
        AC_Lab1/GaussJordan.h)
