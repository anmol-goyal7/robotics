cmake_minimum_required(VERSION 3.16)
project(arm2r LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(arm2r STATIC src/arm2r.cpp)
target_include_directories(arm2r PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

add_executable(test_arm2r tests/test_arm2r.cpp)
target_link_libraries(test_arm2r PRIVATE arm2r)
add_test(NAME test_arm2r COMMAND test_arm2r)

add_executable(sample_workspace examples/sample_workspace.cpp)
target_link_libraries(sample_workspace PRIVATE arm2r)
