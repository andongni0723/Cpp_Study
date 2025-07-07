from collections import deque
from heapq import *
from typing import List

class Solution:
    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
        visited = [[False]*len(grid[0]) for _ in range(len(grid))]
        dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        pq = []

        def check(y, x):
            return 0 <= y < len(grid) and 0 <= x < len(grid[0])

        def bfs(y, x):
            que = deque()
            que.append((y, x, 0))
            visited[y][x] = True
            while que:
                cy, cx, step = que.popleft()
                price = grid[cy][cx]
                if price == 0: continue
                if pricing[0] <= price <= pricing[1]:
                    heappush(pq, (step, price, cy, cx))
                for dy, dx in dirs:
                    ny, nx = cy + dy, cx + dx
                    if check(ny, nx) and not visited[ny][nx]:
                        visited[ny][nx] = True
                        que.append((ny, nx, step+1))

        bfs(start[0], start[1])
        ans = []
        for _ in range(min(k, len(pq))):
            _, _, y, x = heappop(pq)
            ans.append([y, x])
        return ans