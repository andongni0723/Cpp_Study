from typing import List
from heapq import *

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)

        # get operate count list
        queries_diff = [0] * (n + 1)
        for l, r in queries:
            queries_diff[l] += 1
            if r + 1 < n:
                queries_diff[r + 1] -= 1

        # check can become to zero array
        total = 0
        for i in range(n):
            total += queries_diff[i]
            if total < nums[i]: # impossible equals 0
                return -1

        data = [[] for _ in range(n)] # idx: start, value: end
        for l, r in queries:
            data[l].append(r)

        diff = [0] * (n + 1)
        current = 0
        used = 0
        heap = [] # max-heap, (-end)
        for i in range(n):
            current += diff[i]

            for end in data[i]:
                heappush(heap, -end)

            while current < nums[i]:
                end = -heappop(heap)
                used += 1
                diff[i] += 1
                if end + 1 < n:
                    diff[end+1] -= 1
                current += 1

        return len(queries) - used