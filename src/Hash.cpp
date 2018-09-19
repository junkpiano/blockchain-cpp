#include "Hash.h"
#include "../vendor/pikosha2.hpp"

Hash::Hash(string input) {
    std::string hash_hex_str;
    picosha2::hash256_hex_string(input, hash_hex_str);
    this->_value = hash_hex_str;
}

string Hash::getValue() {
  return this->_value;
}
