cmake_minimum_required (VERSION 3.7)
project (crosscompile)

# The version number.
set (crosscompile_VERSION_MAJOR 1)
set (crosscompile_VERSION_MINOR 0)

include_directories("include/")
add_executable(crosscompile src/main.cpp)
