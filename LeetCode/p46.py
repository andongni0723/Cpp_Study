from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        save = []
        ans = []
        n = len(nums)
        used = [False] * n
        def backtrack():
            if len(save) == n:
                ans.append(save.copy())
            for i in range(n):
                if used[i]: continue
                save.append(nums[i])
                used[i] = True
                backtrack()
                save.pop()
                used[i] = False
        backtrack()
        return ans

