cmake_minimum_required (VERSION 2.8)
project(Matrix)
set (CMAKE_CXX_STANDARD 11)
set (gtest_disable_pthreads on)

add_subdirectory (googletest)


add_executable (${PROJECT_NAME} main.cpp matrix.cpp matrixtest.cpp)
target_link_libraries (${PROJECT_NAME} gtest gmock)

