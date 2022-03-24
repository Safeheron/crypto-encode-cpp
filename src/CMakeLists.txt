find_package(CryptoHash REQUIRED)

add_library(${PROJECT_NAME} SHARED
        crypto-encode/hex_imp.c
        crypto-encode/hex.cpp
        crypto-encode/base64_imp.cpp
        crypto-encode/base64.cpp
        crypto-encode/base58.cpp
        crypto-encode/base58_imp.cpp
        )

target_include_directories(${PROJECT_NAME} PRIVATE ${CryptoHash_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} CryptoHash)
