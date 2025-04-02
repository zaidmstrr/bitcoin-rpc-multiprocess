#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdint>

namespace util {
    std::string toHex(const std::vector<uint8_t>& data);
}

#endif // UTIL_H