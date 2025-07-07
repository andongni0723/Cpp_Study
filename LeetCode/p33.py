from typing import List

class Solution:
    def find_min_val_idx(self, data) -> int:
        l, r = -1, len(data)-1
        while l + 1 < r:
            mid = (l + r) // 2
            if data[mid] > data[-1]:
                l = mid
            else:
                r = mid
        return r

    def lower_bound(self, data, l, r, target) -> int:
        while l + 1 < r:
            mid = (l + r) // 2
            if data[mid] < target:
                l = mid
            else:
                r = mid
        return r if data[r] == target else -1

    def search(self, nums: List[int], target: int) -> int:
        min_idx = self.find_min_val_idx(nums)
        print(min_idx)
        if target > nums[-1]:
            return self.lower_bound(nums, -1, min_idx, target)
        else:
            return self.lower_bound(nums, min_idx-1, len(nums), target)