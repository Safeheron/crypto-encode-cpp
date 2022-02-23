//
// Created by 何剑虹 on 2021/6/11.
//

#include "base64.h"
#include "base64_imp.h"

namespace safeheron {
namespace encode {
namespace base64 {

std::string EncodeToBase64(const std::string &data, bool url) {
    return base64_encode(data, url);
}

std::string DecodeFromBase64(const std::string &base64, bool remove_linebreaks) {
    return base64_decode(base64, remove_linebreaks);
}

};
};
};
