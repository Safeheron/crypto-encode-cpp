cmake_minimum_required(VERSION 3.10)
project(test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

find_package(CryptoHash REQUIRED)
if(CryptoHash_FOUND )
    MESSAGE(STATUS "Found CryptoHash!")
endif(CryptoHash_FOUND )

include_directories("../src")

add_executable(base64-test base64-test.cpp)
target_link_libraries( base64-test
        CryptoEncode
        ${GTEST_BOTH_LIBRARIES}
        pthread )
add_test(NAME test-base64 COMMAND base64-test)

add_executable(hex-test hex-test.cpp)
target_link_libraries( hex-test
        CryptoEncode
        ${GTEST_BOTH_LIBRARIES}
        pthread )
add_test(NAME test-hex COMMAND hex-test)



