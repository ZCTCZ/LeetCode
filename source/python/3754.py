class Solution:
    def sumAndMultiply(self, n: int) -> int:
        if n == 0:
            return 0
        n_str = str(n)
        x_str = ""
        sum = 0
        for ch in n_str:
            if ch != '0':
                sum += int(ch)
                x_str += ch
        return sum * int(x_str)
