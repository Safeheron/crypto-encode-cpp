//
// Created by 何剑虹 on 2021/6/11.
//

#ifndef CPP_MPC_HEX_H
#define CPP_MPC_HEX_H

#include <string>

namespace safeheron {
namespace encode {
namespace hex {

std::string DecodeFromHex(const std::string &hex);

std::string EncodeToHex(const std::string &data);

};
};
};

#endif //CPP_MPC_HEX_H
