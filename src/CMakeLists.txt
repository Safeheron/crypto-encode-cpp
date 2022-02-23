cmake_minimum_required(VERSION 3.10)
project(CryptoEncode)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_BUILD_TYPE "Release")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable")

find_package(PkgConfig REQUIRED)
if (NOT PkgConfig_FOUND)
    message(FATAL_ERROR "PkgConfig Not Found!")
endif (NOT PkgConfig_FOUND)
pkg_search_module(PROTOBUF REQUIRED protobuf)  # this looks for opencv.pc file

#set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)
if (NOT OpenSSL_FOUND)
    message(FATAL_ERROR "OpenSSL Not Found!")
endif (NOT OpenSSL_FOUND)

message(STATUS "OPENSSL_INCLUDE_DIR = ${OPENSSL_INCLUDE_DIR}")
message(STATUS "PROTOBUF_LIBRARY = ${PROTOBUF_LIBRARIES}")

add_library(${PROJECT_NAME} SHARED
        crypto-encode/base64_imp.cpp
        crypto-encode/base64.cpp
        crypto-encode/hex_conv.c
        crypto-encode/hex.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROTOBUF_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIR}
        )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${PROTOBUF_LIBRARIES}
        OpenSSL::Crypto
        -ldl
        )
