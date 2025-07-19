from functools import cache

class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def fib(i):
            if i == 1 or i == 2: return i
            return fib(i-1) + fib(i-2)
        return fib(n)