from typing import List

class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        first = second = 0
        idx = -1
        for i, n in enumerate(nums):
            if n > first:
                second = first
                first = n
                idx = i
            elif n > second:
                second = n
        if first >= second * 2:
            return idx
        else:
            return -1