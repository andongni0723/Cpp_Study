from typing import List

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        odd, even, mod = 0, 1, 10**9+7
        sum = ans = 0
        for num in arr:
            sum += num
            ans += even if sum & 1 else odd
            ans %= mod
            if sum & 1: odd += 1
            else: even += 1
        return ans