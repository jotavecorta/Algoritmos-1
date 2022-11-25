cmake_minimum_required(VERSION 3.6)
project(Labo07)

#set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES main.cpp
        ejercicios.cpp
#        cases.cpp
        Test/ejerciciosTEST.cpp)

add_executable(Labo07 ${SOURCE_FILES})

target_link_libraries(Labo07 gtest gtest_main)