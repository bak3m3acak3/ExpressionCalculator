cmake_minimum_required(VERSION 3.9)
project(ExpressionCalculator)

set(CMAKE_CXX_STANDARD 11)

add_executable(ExpressionCalculator main.cpp Expression.cpp Expression.h Integer.cpp Integer.h Addition.cpp Addition.h Subtraction.cpp Subtraction.h Multiplication.cpp Multiplication.h Division.cpp Division.h Exponentiation.cpp Exponentiation.h NthRoot.cpp NthRoot.h Logarithm.cpp Logarithm.h ShuntingYardAlgorithm.cpp ShuntingYardAlgorithm.h)