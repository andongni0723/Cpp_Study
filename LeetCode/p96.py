from functools import cache

class Solution:
    def numTrees(self, n: int) -> int:
        @cache
        def f(i, j):
            if i >= j: return 1
            count = 0
            for root in range(i, j+1):
                count += f(i, root-1) * f(root+1, j)
            return count
        return f(1, n)