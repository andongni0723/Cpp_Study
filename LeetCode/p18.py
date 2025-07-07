from typing import List
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)-3):
            if i > 0 and nums[i] == nums[i-1]: continue
            if nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target: break
            if nums[i] + nums[-1] + nums[-2] + nums[-3] < target: continue

            for j in range(i+1, len(nums)-2):
                if j > i+1 and nums[j] == nums[j - 1]: continue
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target: break
                if nums[i] + nums[j] + nums[-1] + nums[-2] < target: continue

                l, r = j + 1, len(nums) - 1
                while l < r:
                    sum = nums[i] + nums[j] + nums[l] + nums[r]
                    if sum > target:
                        r -= 1
                    elif sum < target:
                        l += 1
                    else:
                        if l == j + 1 or nums[l] != nums[l - 1]:
                            res.append([nums[i], nums[j], nums[l], nums[r]])
                        l += 1
                        r -= 1
        return res