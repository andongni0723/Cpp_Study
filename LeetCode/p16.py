from math import inf
from typing import List
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        min_r = closest = inf

        def check(sum):
            nonlocal min_r, closest
            if abs(target - sum) < min_r:
                min_r = abs(target - sum)
                closest = sum

        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]: continue

            sum = nums[i] + nums[i+1] + nums[i+2]
            if sum > target:
                check(sum)
                break

            sum = nums[i] + nums[-1] + nums[-2]
            if sum < target:
                check(sum)
                continue

            l, r = i+1, len(nums)-1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                print(nums[i], nums[l], nums[r], sum)
                if sum > target:
                    r -= 1
                elif sum < target:
                    l += 1
                else:
                    return target
                check(sum)
        return closest



