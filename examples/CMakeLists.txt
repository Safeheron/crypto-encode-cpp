cmake_minimum_required(VERSION 3.10)
project(test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

find_package(CryptoEncode REQUIRED)
if(CryptoEncode_FOUND )
    MESSAGE(STATUS "============> Found CryptoEncode!")
endif(CryptoEncode_FOUND )

find_package(GTest REQUIRED)
if(GTest_FOUND )
    MESSAGE(STATUS "============> Found GTest!")
endif(GTest_FOUND )

add_executable(base58-test base58-test.cpp)
target_include_directories(base58-test PUBLIC
        ${CryptoEncode_INCLUDE_DIRS}
        ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries( base58-test PUBLIC
        CryptoEncode
        ${GTEST_BOTH_LIBRARIES}
        pthread )