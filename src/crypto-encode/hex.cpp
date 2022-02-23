//
// Created by 何剑虹 on 2021/6/11.
//

#include "hex.h"
#include <stdexcept>
#include "hex_conv.h"

namespace safeheron {
namespace encode {
namespace hex {

std::string DecodeFromHex(const std::string &hex) {
    std::string data;
    int hex_len = hex.length();
    if(hex_len % 2 != 0){
        throw std::runtime_error("Input is not valid hex-encoded data.");
    }
    unsigned int decode_out_len = hex_len / 2;
    unsigned char *decode_out = static_cast<unsigned char *>(malloc(decode_out_len));
    hex2bin(hex.c_str(), decode_out, decode_out_len);
    data.assign((char *)decode_out, decode_out_len);
    free(decode_out);
    return data;
}

std::string EncodeToHex(const std::string &data) {
    std::string hex;
    unsigned int encode_out_len = data.length() * 2 + 1;
    char *encode_out = static_cast<char *>(malloc(encode_out_len));
    bin2hex((const uint8_t *)data.c_str(), data.length(), encode_out, encode_out_len);
    hex.assign((char *)encode_out, encode_out_len - 1);
    free(encode_out);
    return hex;
}

};
};
};