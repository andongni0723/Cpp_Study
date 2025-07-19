from typing import List

# O(n), O(1), One-pass
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        n = len(nums)
        zero_zone, i, two_zone = 0, 0, n-1
        while i <= two_zone:
            if nums[i] == 0:
                nums[zero_zone], nums[i] = nums[i], nums[zero_zone]
                zero_zone += 1
                i += 1
            elif nums[i] == 1:
                i += 1
            else:
                nums[two_zone], nums[i] = nums[i], nums[two_zone]
                two_zone -= 1


# O(2n), O(1), Counting Sort
class Solution2:
    def sortColors(self, nums: List[int]) -> None:
        zero = one = two = 0
        for n in nums:
            if n == 0: zero += 1
            elif n == 1: one += 1
            elif n == 2: two += 1
        for i in range(len(nums)):
            if zero > 0:
                nums[i] = 0
                zero -= 1
            elif one > 0:
                nums[i] = 1
                one -= 1
            elif two > 0:
                nums[i] = 2
                two -= 1