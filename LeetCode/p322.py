from math import inf
from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [[None] * (amount+1) for _ in range(len(coins))]
        def f(i, w): # 對第 i 種coin, 組成 w 元的 min coin count
            if w == 0: return 0
            if i < 0 or w < 0: return inf
            if dp[i][w] is not None: return dp[i][w]
            dp[i][w] = min(f(i-1, w), f(i, w-coins[i]) + 1)
            return dp[i][w]
        r = f(len(coins)-1, amount)
        return r if r < inf else -1