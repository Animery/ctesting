cmake_minimum_required(VERSION 3.24)
project(tests)

set(TEST_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
)

add_executable(tests ${TEST_SOURCE})

add_test(NAME Test_1 COMMAND tests test_1)
add_test(NAME Test_2 COMMAND tests test_2)
add_test(NAME Test_3 COMMAND tests test_3)