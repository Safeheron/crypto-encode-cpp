cmake_minimum_required(VERSION 3.10)
project(CryptoEncode)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")

add_library(${PROJECT_NAME} SHARED
        crypto-encode/base64_imp.cpp
        crypto-encode/base64.cpp
        crypto-encode/hex_conv.c
        crypto-encode/hex.cpp
        )

