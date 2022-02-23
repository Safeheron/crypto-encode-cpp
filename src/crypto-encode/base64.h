//
// Created by 何剑虹 on 2021/6/11.
//

#ifndef CPP_MPC_BASE64_H
#define CPP_MPC_BASE64_H

#include <string>

namespace safeheron {
namespace encode {
namespace base64 {

std::string EncodeToBase64(const std::string &data, bool url = false);

std::string DecodeFromBase64(const std::string &base64, bool remove_linebreaks = false);

};
};
};

#endif //CPP_MPC_BASE64_H
