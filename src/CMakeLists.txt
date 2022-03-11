cmake_minimum_required(VERSION 3.10)
project(CryptoEncode)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")

find_package(CryptoHash REQUIRED)
if(CryptoHash_FOUND )
    MESSAGE(STATUS "Found CryptoHash!")
endif(CryptoHash_FOUND )

add_library(${PROJECT_NAME} SHARED
        crypto-encode/hex_imp.c
        crypto-encode/hex.cpp
        crypto-encode/base64_imp.cpp
        crypto-encode/base64.cpp
        crypto-encode/base58.cpp
        crypto-encode/base58_imp.cpp
        )


target_include_directories(${PROJECT_NAME} PUBLIC ${CryptoHash_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} CryptoHash)
