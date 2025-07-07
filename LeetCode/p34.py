from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        l, r = -1, len(nums)
        while l +1 != r:
            mid = l+(r-l)//2
            if nums[mid] < target:
                l = mid
            else:
                r = mid
        s = r
        l, r = -1, len(nums)
        while l+1 != r:
            mid = l+(r-l)//2
            if nums[mid] <= target:
                l = mid
            else:
                r = mid
        e = l
        return [s, e] if s <= e else [-1, -1]