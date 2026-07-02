#include <algorithm>
#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  int maxNumberOfBalloons(std::string text) {
    std::array<int, 26> count{};

    for (auto ch : text) {
      ++count[ch - 'a'];
    }

    int a_cnts = count['a' - 'a'];
    int b_cnts = count['b' - 'a'];
    int l_cnts = count['l' - 'a'];
    int o_cnts = count['o' - 'a'];
    int n_cnts = count['n' - 'a'];

    std::vector<int> balloon_cnts{a_cnts, b_cnts, l_cnts >> 1, o_cnts >> 1, n_cnts};
    return *std::min_element(balloon_cnts.begin(), balloon_cnts.end());
  }
};
