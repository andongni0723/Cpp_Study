class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        add = []
        for i in range(len(nums)-1):
            plus = nums[i] + nums[i+1]
            if plus in add:
                return True
            else:
                add.append(plus)
        return False

    