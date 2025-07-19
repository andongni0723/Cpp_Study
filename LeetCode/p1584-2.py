from typing import List



# Kruskal algorithm
class Solution:
    def distance(self, p1: List[int], p2: List[int]) -> int:
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        edges = []
        for i in range(n):
            for j in range(i+1, n):
                edges.append((self.distance(points[i], points[j]), i, j))

        edges.sort()

        dsu = DSU(n)
        ans = current = 0
        for w, a, b in edges:
            if dsu.union(a, b):
                ans += w
                current += 1
                if current == n - 1:
                    break
        return ans

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y) -> bool:
        if self.size[y] > self.size[x]: x, y = y, x
        rx, ry = self.find(x), self.find(y)
        if rx == ry: return False
        self.parent[ry] = rx
        self.size[rx] += self.size[ry]
        return True