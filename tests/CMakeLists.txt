cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(tests)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/simple_test)

set(TEST_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
)

add_executable(tests ${TEST_SOURCE})
target_link_libraries(tests PRIVATE simple_test)
target_compile_features(tests PRIVATE cxx_std_17)

add_test(NAME Test_1 COMMAND tests test_1)
add_test(NAME Test_2 COMMAND tests test_2)