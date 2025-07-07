from functools import cache
from typing import List
from math import inf

class Solution:
    def minCost(self, n: int, cost: List[List[int]]) -> int:
        # the min cost of
        # print i-th pair to (n//2-1)-th
        # with color of i-th pair is (c1, c2)
        @cache
        def dfs(i, c1, c2):
            if i == n // 2: return 0
            ans = inf
            for j in range(3):
                if j == c1: continue
                for k in range(3):
                    if k == c2 or j == k: continue
                    ans = min(ans, dfs(i+1, j, k) + cost[i][j] + cost[n-i-1][k])
            return ans
        return dfs(0, -1, -1)