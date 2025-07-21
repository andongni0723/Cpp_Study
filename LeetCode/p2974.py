from prelude import *
class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        ans = []
        heapify(nums)
        while nums:
            a = heappop(nums)
            b = heappop(nums)
            ans.append(b)
            ans.append(a)
        return ans