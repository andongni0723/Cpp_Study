from typing import List
class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        new = [nums[0]]
        for i in nums[1:]:
            if i != new[-1]:
                new.append(i)
        res = 0
        for i in range(1, len(new)-1):
            if (new[i-1] < new[i] and new[i+1] < new[i]) or \
               (new[i-1] > new[i] and new[i+1] > new[i]):
                res += 1
        return res