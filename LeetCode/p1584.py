from heapq import heappop, heappush
from math import inf
from typing import List

# Prim algorithm

class Solution:
    def distance(self, p1: List[int], p2: List[int]) -> int:
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        in_mst = [False] * n
        distance = [inf] * n
        distance[0] = 0
        min_heap = [] # (distance, point idx)
        cost = 0

        heappush(min_heap, (0, 0))

        while min_heap:
            d, idx = heappop(min_heap)
            if in_mst[idx]:
                continue

            in_mst[idx] = True
            cost += d

            for i in range(n):
                new_dist = self.distance(points[i], points[idx])
                if not in_mst[i] and new_dist < distance[i]:
                    distance[i] = new_dist
                    heappush(min_heap, (new_dist, i))

        return cost
