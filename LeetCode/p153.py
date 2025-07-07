from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = -1, len(nums)
        while l + 1 < r:
            mid = (l + r) // 2
            if nums[mid] > nums[-1]:
                l = mid
            else:
                r = mid
        return nums[r]