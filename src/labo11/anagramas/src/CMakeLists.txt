cmake_minimum_required(VERSION 3.9)
project(anagramas)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

SET(SOURCE_FILES
        main.cpp
        anagramas.cpp
        auxiliares.cpp
        auxiliares.h
        test/anagramasTEST.cpp
        )


add_executable(anagramas ${SOURCE_FILES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(anagramas gtest gtest_main)
