set(PROJECT_NAME pull-stream-test)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/cmake-build/bin)

add_executable(${PROJECT_NAME} basic-test.cpp
                              end_or_error_test.cpp)

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
