from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        save = []
        ans = []
        n = len(nums)
        used = [False] * n
        nums.sort()
        def backtrack():
            if len(save) == n:
                ans.append(save.copy())
            for i in range(n):
                if used[i]: continue
                if i > 0 and nums[i] == nums[i-1] and used[i-1]: continue
                save.append(nums[i])
                used[i] = True
                backtrack()
                save.pop()
                used[i] = False
        backtrack()
        return ans