from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        time = farthest = end = 0
        n = len(nums)
        if n <= 1: return 0
        for i, num in enumerate(nums[:-1]):
            farthest = max(farthest, i + num)
            if end == i:
                time += 1
                end = farthest
                if end >= n - 1:
                    return time
        return time