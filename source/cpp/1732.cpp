#include <algorithm>
#include <vector>

class Solution {
public:
  int largestAltitude(std::vector<int> &gain) {
    int ans = 0;
    int cur = 0;
    for (auto e : gain) {
      cur += e;
      ans = std::max(ans, cur);
    }

    return ans;
  }
};
