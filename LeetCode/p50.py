class Solution:
    def myPow(self, x: float, n: int) -> float:
        ans = 1
        neg = n < 0
        n = abs(n)
        while n > 0:
            if n & 1:
                ans *= x
            x *= x
            n >>= 1
        return 1/ans if neg else ans