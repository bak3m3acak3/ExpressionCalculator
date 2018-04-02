cmake_minimum_required(VERSION 3.9)
project(ExpressionCalculator)

set(CMAKE_CXX_STANDARD 11)

add_executable(ExpressionCalculator main.cpp Expression.cpp Expression.h)