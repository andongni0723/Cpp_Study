from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        for x in range(1, n):
            grid[0][x] += grid[0][x-1]

        for y in range(1, m):
            grid[y][0] += grid[y-1][0]

        for y in range(1, m):
            for x in range(1, n):
                grid[y][x] += min(grid[y-1][x], grid[y][x-1])

        return grid[m-1][n-1]