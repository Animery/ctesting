cmake_minimum_required(VERSION 3.24)
project(new_project VERSION 0.1.0)

file(GLOB TARGET_SRC
    ./src/*.cpp
)

add_executable(main ${TARGET_SRC})

include(CTest)
enable_testing()

if(BUILD_TESTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()