from functools import cache
from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_idx = 0
        for i, num in enumerate(nums):
            if i > max_idx: return False
            max_idx = max(max_idx, i + num)
        return True