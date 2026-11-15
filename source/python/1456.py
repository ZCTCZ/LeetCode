class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        result, temp, left, right = 0, 0, 0, 0
        vowels: set = {"a", "e", "i", "o", "u"}
        while right < len(s):
            if s[right] in vowels:
                temp += 1
            if right < k - 1:
                right += 1
                continue
            result = max(result, temp)  # 窗口一凑满就统计
            if s[left] in vowels:
                temp -= 1
            left += 1
            right += 1

        return result


print(Solution().maxVowels("abciiidef", 3))
