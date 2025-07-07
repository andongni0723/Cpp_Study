class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0: return 0
        ans = 0
        sign = -1 if (dividend ^ divisor < 0) else 1
        abs_dend, abs_d = abs(dividend), abs(divisor)
        while abs_dend >= abs_d:
            mul = 1
            d = abs_d
            while (d << 1) <= abs_dend:
                d <<= 1
                mul <<= 1
            abs_dend -= d
            ans += mul

        return max(-(1<<31), min((1<<31)-1, ans * sign))