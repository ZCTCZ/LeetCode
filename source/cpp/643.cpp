#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  double findMaxAverage(std::vector<int> &nums, int k) {
    double result = -std::numeric_limits<double>::infinity();
    int sum = 0, left = 0, right = 0;
    while (right < nums.size()) {
      sum += nums[right];
      if (right < k - 1) {
        ++right;
        continue;
      }
      result = std::max(result, 1.0 * sum / k);
      sum -= nums[left];
      ++left;
      ++right;
    }
    return result;
  }
};