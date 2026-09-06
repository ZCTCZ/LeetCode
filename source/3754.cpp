#include <string>

class Solution {
public:
  long long sumAndMultiply(int n) {
    if (n == 0) {
      return 0;
    }

    std::string n_str = std::to_string(n);
    std::string x_str;
    int sum = 0;
    for (auto ch : n_str) {
      if (ch != '0') {
        x_str.push_back(ch);
        sum += ch - '0';
      }
    }

    return sum * std::stoll(x_str);
  }
};