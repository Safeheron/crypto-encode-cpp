//
// Created by 何剑虹 on 2020/10/22.
//
#include <cstring>
#include <google/protobuf/stubs/common.h>
#include "gtest/gtest.h"
#include "../src/crypto-encode/base64.h"
#include "../src/crypto-encode/hex.h"
#include "../src/crypto-encode/hex_conv.h"

void test(const char * pdata, int data_len, const char* pbase64, int base64_len){
    std::string data, base64;

    //encode
    data.assign(pdata, data_len);
    std::cout << data.length() << std::endl;
    base64 = safeheron::encode::base64::EncodeToBase64(data);
    EXPECT_EQ(base64_len, base64.length());
    EXPECT_TRUE(strcmp(pbase64, base64.c_str()) == 0);

    // decode
    data = safeheron::encode::base64::DecodeFromBase64(base64);
    EXPECT_TRUE(strcmp(pdata, data.c_str())== 0);

}

TEST(Base64, ToBase64_FromBase64)
{
    test("", 0, "", 0);
    test("f", 1, "Zg==", 4);
    test("fo", 2, "Zm8=", 4);
    test("foo", 3, "Zm9v", 4);
    test("foob", 4, "Zm9vYg==", 8);
    test("fooba", 5, "Zm9vYmE=", 8);
    test("foobar", 6, "Zm9vYmFy", 8);
}

TEST(Base64, ToUrlBase64_FromUrlBase64)
{
    char num1[32] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,
                     0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20};
    std::string data, base64, data2;
    data.assign(num1, 32);
    base64 = safeheron::encode::base64::EncodeToBase64(data, true);
    std::cout << "base64: " << base64 << std::endl;
    data2 = safeheron::encode::base64::DecodeFromBase64(base64);
    EXPECT_TRUE( 0 == memcmp(data.c_str(), data2.c_str(), 32) );
}

TEST(Base64, Example_1)
{
    const char *hex = "0a40613034333464396534376633633836323335343737633762316165366165356433343432643439623139343363326237353261363865326134376532343763371240383933616261343235343139626332376133623663376536393361323463363936663739346332656438373761313539336362656535336230333733363864371a09736563703235366b31";
    char bin[2000];
    memset(bin, 0, 2000);
    printf("%zu\n", strlen(hex));
    hex2bin(hex, reinterpret_cast<uint8_t *>(bin), 2000);


    std::string data, hex_str, data2;
    data.assign(bin, 143);
    hex_str = safeheron::encode::hex::EncodeToHex(data);
    std::cout << "base64: " << hex_str << std::endl;
    data2 = safeheron::encode::hex::DecodeFromHex(hex_str);
    std::cout << "len1: " << data.length() << std::endl;
    std::cout << "len2: " << data2.length() << std::endl;
    EXPECT_TRUE( data.length() == data2.length());
    EXPECT_TRUE( 0 == memcmp(data.c_str(), data2.c_str(), 32) );
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    google::protobuf::ShutdownProtobufLibrary();
    return ret;
}
