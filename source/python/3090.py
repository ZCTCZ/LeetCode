class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        if s == "":
            return 0
        left, right = 0, 0
        appear_cnts = {}
        ans = 0
        while right < len(s):
            if s[right] in appear_cnts and appear_cnts[s[right]] == 2:
                ans = max(ans, right - left)
                while appear_cnts[s[right]] == 2:
                    appear_cnts[s[left]] -= 1
                    left += 1
            else:
                if s[right] in appear_cnts:
                    appear_cnts[s[right]] += 1
                else:
                    appear_cnts[s[right]] = 1
            right += 1
        ans = max(ans, right - left)
        return ans
