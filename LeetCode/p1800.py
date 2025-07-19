from typing import List

class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans = total = prev = nums[0]
        for n in nums[1:]:
            if n > prev:
                total += n
            else:
                print(total, ans)
                ans = max(ans, total)
                total = n
            prev = n
        return max(ans, total)