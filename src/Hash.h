#include <cstdint>
#include <iostream>

using namespace std;

class Hash {
 public:
  Hash(string input);
  string getValue();
 private:
  string _value;
};
