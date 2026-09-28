class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        left, right = 0, 0
        last_appear = {}
        max_len = 0
        while right < len(s):
            if s[right] in last_appear and last_appear[s[right]] >= left:
                max_len = max(max_len, right - left)
                left = last_appear[s[right]] + 1
            last_appear[s[right]] = right
            right += 1
        max_len = max(max_len, right - left)
        return max_len
