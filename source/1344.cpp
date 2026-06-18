#include <algorithm>
#include <cstdlib>
#include <print>
class Solution {
public:
    double angleClock(int hour, int minutes)
    {
        int minutes_degree = minutes * 6; // 分针从 12 点方向顺时针旋转的角度
        double hour_degree = hour * 30 % 360 + minutes_degree / 12.0; // 时针从 12 点方向顺时针旋转的角度

        return std::min(std::abs(hour_degree - minutes_degree), 360 - std::abs(hour_degree - minutes_degree));
    }
};

int main(int /*argc*/, char* /*arcv*/[])
{
    std::println("{}", Solution().angleClock(12, 30));
    return 0;
}
