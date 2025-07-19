class Solution:
    def alternateDigitSum(self, n: int) -> int:
        sign, ans = 1, 0
        for c in str(n):
            num = int(c)
            ans += num * sign
            sign *= -1
        return ans
