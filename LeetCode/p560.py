from collections import defaultdict
from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        sum = 0
        seem = defaultdict(int)
        seem[0] = 1
        for n in nums:
            sum += n
            ans += seem[sum - k]
            seem[sum] += 1
        return ans