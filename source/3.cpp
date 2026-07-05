#include <algorithm>
#include <array>
#include <print>
#include <string>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string& s) {
    int n = s.size();
    if (n == 0) {
      return 0;
    }

    int ans = 0;
    int left = 0, right = 0;
    std::array<int, 128> position_record;
    position_record.fill(-1);

    while (right < n) {
      // s[right] 已经在子串 s[left : right) 里出现过
      if (position_record[s[right]] != -1 && position_record[s[right]] >= left) {
        ans = std::max(ans, right - left);
        left = position_record[s[right]] + 1;  // 更新窗口左边界
        position_record[s[right]] = right;
        ++right;
      } else {
        position_record[s[right]] = right;
        ++right;
      }
    }

    ans = std::max(ans, right - left);
    return ans;
  }
};

int main(int /*argc*/, char* /*arcv*/[]) {
  std::string s{" "};
  std::println("{}", Solution().lengthOfLongestSubstring(s));
  return 0;
}