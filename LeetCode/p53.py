from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = nums[0]
        cur_max = nums[0]
        for n in nums[1:]:
            cur_max = max(cur_max + n, n)
            ans = max(ans, cur_max)
        return ans