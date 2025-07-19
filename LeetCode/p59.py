from typing import List

class Solution:
    def check(self, y, x, n):
        return 0 <= x < n and 0 <= y < n

    def generateMatrix(self, n: int) -> List[List[int]]:
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        ans = [[0] * n for _ in range(n)]
        x = y = dir = 0
        for i in range(1, n * n + 1):
            ans[y][x] = i
            ny, nx = y + dirs[dir][0], x + dirs[dir][1]
            if not self.check(ny, nx, n) or ans[ny][nx] != 0:
                dir = (dir + 1) % 4
                ny, nx = y + dirs[dir][0], x + dirs[dir][1]
            y, x = ny, nx
        return ans
