from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]: continue
            if nums[i] + nums[i+1] + nums[i+2] > 0: break
            if nums[i] + nums[-1] + nums[-2] < 0: continue

            l, r = i+1, len(nums)-1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                if sum > 0:
                    r -= 1
                elif sum < 0:
                    l += 1
                else:
                    if l == i + 1 or nums[l] != nums[l-1]:
                        res.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1

        return res
