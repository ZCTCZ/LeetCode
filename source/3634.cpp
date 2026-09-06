#include <algorithm>
#include <print>
#include <vector>

class Solution {
public:
  int minRemoval(std::vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0 || n == 1) {
      return 0;
    }

    std::sort(nums.begin(), nums.end());
    int left = 0;
    int max_len = 0;

    for (int i = 0; i < n; ++i) {
      while (1LL * nums[left] * k < nums[i]) {
        ++left;
      }

      max_len = std::max(max_len, i - left + 1);
    }

    return n - max_len;
  }
};

int main(int /*argc*/, char * /*arcv*/[]) {
  std::vector<int> nums{466, 306, 76, 17, 60, 246, 341, 284};
  std::println("{}", Solution().minRemoval(nums, 2));
  return 0;
}