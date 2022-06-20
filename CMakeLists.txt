cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(pull-stream-project VERSION 1.0)

enable_testing()
add_subdirectory(third-party/googletest-release-1.11.0)
include_directories(third-party/googletest-release-1.11.0/googletest/include)

include_directories(include)


add_subdirectory(src)
add_subdirectory(test)