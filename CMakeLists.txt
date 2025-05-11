cmake_minimum_required(VERSION 3.31)
project(CourseProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(CourseProject main.cpp
        Figure.cpp
        Figure.h
        Rhomb.cpp
        Rhomb.h
        MyRectangle.cpp
        MyRectangle.h)
