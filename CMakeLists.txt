cmake_minimum_required (VERSION 2.8.11)
project (calc)
set(CMAKE_CXX_FLAGS "-Wall -std=c++1y")
add_subdirectory (lib)


add_executable (calc2postfix evaluate_postfix.cpp)
target_link_libraries (calc2postfix LINK_PUBLIC lib)

add_executable (calc2sexpr sexpression.cpp)
target_link_libraries (calc2sexpr LINK_PUBLIC lib)

add_executable (calc calc.cpp)
target_link_libraries (calc LINK_PUBLIC lib)
