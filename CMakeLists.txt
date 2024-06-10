project(dupa CXX)
cmake_minimum_required(VERSION 3.12)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

SET(INC ${CMAKE_CURRENT_SOURCE_DIR}/inc/)

add_subdirectory(src)
add_subdirectory(test)
