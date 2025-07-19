from typing import List

class Solution:
    def in_bound(self, x, y):
        return 0 <= x < 8 and 0 <= y < 8

    def numRookCaptures(self, board: List[List[str]]) -> int:
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        rx, ry = -1, -1
        ans = 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == 'R':
                    ry, rx = i, j

        for dx, dy in dirs:
            x, y= rx + dx, ry + dy
            while self.in_bound(x, y):
                char = board[y][x]
                if char == 'p':
                    ans += 1
                    break
                if char == 'B':
                    break
                x += dx
                y += dy

        return ans


print("ans"[1:])