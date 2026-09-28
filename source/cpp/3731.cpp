#include <algorithm>
#include <array>
#include <print>
#include <vector>

class Solution {
public:
  std::vector<int> findMissingElements(std::vector<int> &nums) {
    auto [min_pos, max_pos] = std::minmax_element(nums.begin(), nums.end());
    if (*max_pos - *min_pos + 1 == nums.size()) {
      return {};
    }

    std::vector<int> ans;
    std::array<int, 100> arr;
    arr.fill(0);
    std::for_each(nums.begin(), nums.end(), [&arr](int num) { arr[num - 1] = 1; });
    for (int i = *min_pos + 1; i < *max_pos; ++i) {
      if (arr[i - 1] == 0) {
        ans.emplace_back(i);
      }
    }
    return ans;
  }
};

int main(int /*argc*/, char * /*arcv*/[]) {
  std::vector<int> nums{1, 4, 2, 5};
  std::println("{}", Solution().findMissingElements(nums));
  return 0;
}