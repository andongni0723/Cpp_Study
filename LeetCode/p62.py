from math import factorial, comb


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return comb(m+n-2, m-1)
        # a.k.a
        # return factorial(m+n-2) // (factorial(m-1) * factorial(n-1))