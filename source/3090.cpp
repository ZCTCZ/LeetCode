#include <algorithm>
#include <array>
#include <print>
#include <string>

class Solution {
 public:
  int maximumLengthSubstring(std::string s) {
    int n = s.size();
    if (n == 0) {
      return 0;
    }

    std::array<int, 26> char_cnts;
    char_cnts.fill(0);
    int ans = 0;

    int left = 0, right = 0;
    while (right < s.size()) {
      if (char_cnts[s[right] - 'a'] == 2) {
        ans = std::max(ans, right - left);
        while (char_cnts[s[right] - 'a'] == 2) {
          --char_cnts[s[left] - 'a'];
          ++left;
        }
      }

      ++char_cnts[s[right] - 'a'];
      ++right;
    }

    ans = std::max(ans, right - left);
    return ans;
  }
};

int main(int /*argc*/, char* /*arcv*/[]) {
  std::println("{}", Solution().maximumLengthSubstring("bcbbbcba"));
  return 0;
}