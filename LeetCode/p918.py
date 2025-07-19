from typing import List

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        cur_max = max_sum = nums[0]
        cur_min = min_sum = nums[0]
        total = nums[0]
        for n in nums[1:]:
            total += n

            cur_max = max(cur_max + n, n)
            max_sum = max(max_sum, cur_max)

            cur_min = min(cur_min + n, n)
            min_sum = min(min_sum, cur_min)

        if min_sum == total:
            return max_sum
        return max(max_sum, total - min_sum)
