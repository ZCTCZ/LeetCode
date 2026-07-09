class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0
        ans, left, right, cnt_of_not_1 = 0, 0, 0, 0
        while right < len(nums):
            if nums[right] != 1:
                cnt_of_not_1 += 1
                if cnt_of_not_1 > 1:
                    ans = max(ans, right - left)
                    while cnt_of_not_1 > 1:
                        if nums[left] != 1:
                            cnt_of_not_1 -= 1
                        left += 1
            right += 1
        ans = max(ans, right - left)
        return ans - 1
