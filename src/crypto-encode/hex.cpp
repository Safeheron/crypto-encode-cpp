//
// Created by 何剑虹 on 2021/6/11.
//

#include "hex.h"
#include <stdexcept>
#include <memory>
#include "hex_imp.h"

namespace safeheron {
namespace encode {
namespace hex {

std::string DecodeFromHex(const std::string &hex) {
    std::string data;
    int hex_len = hex.length();
    if(hex_len == 0) return data;
    if(hex_len % 2 != 0){
        throw std::runtime_error("Input is not valid hex-encoded data(length is even).");
    }
    unsigned int decode_out_len = hex_len / 2;
    std::unique_ptr<uint8_t[]> decode_out(new uint8_t[decode_out_len]);
    tallymarker_hex2bin(hex.c_str(), decode_out.get(), decode_out_len);
    data.assign((char *)decode_out.get(), decode_out_len);
    return data;
}

std::string EncodeToHex(const std::string &data) {
    return EncodeToHex(reinterpret_cast<const unsigned char *>(data.c_str()), data.length());
}

std::string EncodeToHex(const unsigned char * buf, size_t buf_len){
    std::string hex;
    unsigned int encode_out_len = buf_len * 2 + 1;
    std::unique_ptr<char[]> encode_out(new char [encode_out_len]);
    tallymarker_bin2hex(buf, buf_len, encode_out.get(), encode_out_len);
    hex.assign((char *)encode_out.get(), encode_out_len - 1);
    return hex;
}

};
};
};
