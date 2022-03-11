/**
 * Why base-58 instead of standard base-64 encoding?
 * - Don't want 0OIl characters that look the same in some fonts and
 *      could be used to create visually identical looking data.
 * - A string with non-alphanumeric characters is not as easily accepted as input.
 * - E-mail usually won't line-break if there's no punctuation to break at.
 * - Double-clicking selects the whole string as one word if it's all alphanumeric.
 */
#ifndef BITCOIN_BASE58_H
#define BITCOIN_BASE58_H

#include <string>
#include <vector>

namespace safeheron {
namespace encode {
namespace base58 {

std::string EncodeToBase58(const std::string &data);

std::string EncodeToBase58(unsigned char const *buf, size_t buf_len);

std::string DecodeFromBase58(const std::string &base58);


std::string EncodeToBase58Check(const std::string &data);

std::string EncodeToBase58Check(unsigned char const *buf, size_t buf_len);

std::string DecodeFromBase58Check(const std::string &base58);

}
}
}
#endif // BITCOIN_BASE58_H
