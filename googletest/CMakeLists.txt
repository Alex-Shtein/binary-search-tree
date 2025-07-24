cmake_minimum_required(VERSION 3.14)

project(mp_HW01)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_library(mp_HW01Lib SHARED ../Task1/src/main.cpp)

add_executable(mp_HW01Tests ../Task1.Tests/BinaryTree.tests.cpp)

target_link_libraries(mp_HW01Tests mp_HW01Lib gmock gtest gtest_main pthread)