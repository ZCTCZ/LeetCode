#include <algorithm>
#include <array>
#include <print>
#include <vector>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins)
    {
        std::array<int, 100001> counts{};
        for (int i = 0; i < costs.size(); ++i) {
            ++counts[costs[i]];
        }

        int ans = 0;
        for (int i = 1; i <= 100000; ++i) {
            if (coins < i) {
                break;
            }

            if (i <= coins && counts[i] >= 0) {
                int cnt = std::min(coins / i, counts[i]); // 当前可以购买价格为 i 的雪糕的支数
                ans += cnt;
                coins -= i * cnt;
            }
        }

        return ans;
    }
};

int main(int /*argc*/, char* /*arcv*/[])
{
    std::vector<int> costs{1, 6, 3, 1, 2, 5};
    int coins = 20;
    std::println("{}", Solution().maxIceCream(costs, coins));
    return 0;
}
