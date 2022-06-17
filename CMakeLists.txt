cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

project(pull-stream-project VERSION 1.0)

add_executable(pull-stream-demo ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

include_directories(include)

