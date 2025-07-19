from typing import List

class Solution:
    def check(self, x, y, nx, ny):
        return 0 <= x < nx and 0 <= y < ny

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        ans = []
        n, m = len(matrix), len(matrix[0])
        visited = [[False] * m for _ in range(n)]
        x = y = dir = 0
        for _ in range(n * m):
            ans.append(matrix[y][x])
            visited[y][x] = True
            ny, nx = y + dirs[dir][0], x + dirs[dir][1]
            if not self.check(nx, ny, m, n) or visited[ny][nx]:
                dir = (dir + 1) % 4
                ny, nx = y + dirs[dir][0], x + dirs[dir][1]
            y, x = ny, nx
        return ans

