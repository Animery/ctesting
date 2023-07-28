cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(simple_test)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/simple_test.cpp
)

add_library(simple_test STATIC ${SOURCE})
target_compile_features(simple_test PRIVATE cxx_std_17)

target_include_directories(simple_test PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)