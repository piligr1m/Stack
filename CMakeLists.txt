cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_library(stack1 INTERFACE)
add_library(stack2 INTERFACE)

add_executable(stack sources/main.cpp)

target_include_directories(stack1 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(stack2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(stack stack1 stack2)
