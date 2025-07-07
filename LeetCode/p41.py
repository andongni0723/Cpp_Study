from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[i] != nums[nums[i] - 1]:
                target = nums[i] - 1
                nums[i], nums[target] = nums[target], nums[i]
        for i, n in enumerate(nums):
            if i+1 != n:
                return i + 1
        return n + 1