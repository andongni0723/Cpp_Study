from typing import List

class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            find = False
            for i in range(n+1):
                if i | (i + 1) == n:
                    ans.append(i)
                    find = True
                    break
            if not find:
                ans.append(-1)
        return ans