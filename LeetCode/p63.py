from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        if obstacleGrid[0][0] == 1 or obstacleGrid[m-1][n-1] == 1: return 0
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        for x in range(1, n):
            if obstacleGrid[0][x] == 0 and dp[0][x-1] == 1:
                dp[0][x] = 1

        for y in range(1, m):
            if obstacleGrid[y][0] == 0 and dp[y-1][0] == 1:
                dp[y][0] = 1

        for y in range(1, m):
            for x in range(1, n):
                if obstacleGrid[y][x] == 1: continue
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1]

        return dp[m - 1][n - 1]