cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(stack)

add_library(stack INTERFACE)

add_executable(stack sources/main.cpp)

target_include_directories(stack INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(stack)
