find_package(GTest REQUIRED)
find_package(CryptoHash REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
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


add_executable(base58-test base58-test.cpp)
target_link_libraries( base58-test
        CryptoEncode
        ${GTEST_BOTH_LIBRARIES}
        pthread )
add_test(NAME test-base58 COMMAND base58-test)
