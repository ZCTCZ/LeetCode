#include <algorithm>
#include <print>
#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || n == 1) {
      return n;
    }

    int ans = 0;
    int left = 0, right = 0;
    int cnt_of_not_1 = 0;
    while (right < n) {
      if (nums[right] != 1) {
        ++cnt_of_not_1;
        if (cnt_of_not_1 > 1) {
          ans = std::max(ans, right - left);
          while (cnt_of_not_1 > 1) {
            if (nums[left] != 1) {
              --cnt_of_not_1;
            }
            ++left;
          }
        }
      }

      ++right;
    }

    ans = std::max(ans, right - left);
    return ans - 1;
  }
};

int main(int /*argc*/, char* /*arcv*/[]) {
  std::vector<int> nums{1, 1, 0, 1};
  std::println("{}", Solution().longestSubarray(nums));
  return 0;
}