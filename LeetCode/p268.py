from typing import List
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans = n = len(nums)
        for i in range(n):
            ans ^= nums[i]
            ans ^= i
        return ans