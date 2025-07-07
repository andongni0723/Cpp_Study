class Solution:
    def reverse(self, x: int) -> int:
        n = int(str(x)[::-1] if x >= 0 else '-' + str(x)[1:][::-1])
        return n if -2**31 <= n <= 2**31-1 else 0