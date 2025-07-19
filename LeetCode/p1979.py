from math import inf
from typing import List

class Solution:
    def findGCD(self, nums: List[int]) -> int:
        small, big = inf, 0

        for n in nums:
            small = min(small, n)
            big = max(big, n)

        def gcd(x, y):
            while y:
                x, y = y, x % y
            return x

        return gcd(small, big)
