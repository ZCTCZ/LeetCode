class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        result, sum, left, right = float("-inf"), 0, 0, 0
        while right < len(nums):
            sum += nums[right]
            if right < k - 1:
                right += 1
                continue
            result = max(result, sum / k)
            sum -= nums[left]
            left += 1
            right += 1
        return result


if __name__ == "__main__":
    print(Solution().findMaxAverage([1, 12, -5, -6, 50, 3], 4))
