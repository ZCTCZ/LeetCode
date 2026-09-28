class Solution:
    def minRemoval(self, nums: list[int], k: int) -> int:
        if len(nums) == 0 or len(nums) == 1:
            return 0
        nums.sort()
        left, max_len = 0, 0
        for i in range(0, len(nums)):
            while nums[left] * k < nums[i]:
                left += 1
            max_len = max(max_len, i - left + 1)
        return len(nums) - max_len


def main() -> int:
    nums = [1, 6, 2, 9]
    print(Solution().minRemoval(nums, 3))
    return 0


if __name__ == "__main__":
    main()
