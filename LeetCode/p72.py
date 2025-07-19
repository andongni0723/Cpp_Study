from functools import cache


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for x in range(1, m + 1):
            dp[0][x] = x
        for y in range(1, n + 1):
            dp[y][0] = y

        for y in range(1, n + 1):
            for x in range(1, m + 1):
                if word1[y-1] == word2[x-1]:
                    dp[y][x] = dp[y-1][x-1]
                else:
                    insert = dp[y][x-1] + 1
                    delete = dp[y-1][x] + 1
                    replace = dp[y-1][x-1] + 1
                    dp[y][x] = min(insert, delete, replace)

        return dp[n][m]

class Solution2:
    def minDistance(self, word1: str, word2: str) -> int:
        n, m = len(word1), len(word2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        @cache
        def dfs(y, x):
            if y == 0: return x
            if x == 0: return y
            if word1[y-1] == word2[x-1]:
                return dfs(y-1, x-1)
            else:
                insert = dfs(y, x-1)
                delete = dfs(y-1, x)
                replace = dfs(y-1, x-1)
                return min(insert, delete, replace) + 1

        return dfs(n, m)