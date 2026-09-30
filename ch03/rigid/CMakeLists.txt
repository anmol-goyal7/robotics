cmake_minimum_required(VERSION 3.16)
project(rigid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

find_package(Eigen3 REQUIRED NO_MODULE)

# Fetched before add_compile_options so our warning flags don't apply to gtest.
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.18.0
)
FetchContent_MakeAvailable(googletest)

add_compile_options(-Wall -Wextra -Wpedantic -Werror=return-type)

add_library(rigid STATIC src/rigid.cpp)
target_include_directories(rigid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(rigid PUBLIC Eigen3::Eigen)

enable_testing()
include(GoogleTest)

add_executable(test_rigid tests/test_rigid.cpp)
target_link_libraries(test_rigid PRIVATE rigid GTest::gtest_main)
gtest_discover_tests(test_rigid)
