from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_len = 0
        for n in num_set:
            if n - 1 in num_set: continue
            cur, cur_len = n, 1
            while cur + 1 in num_set:
                cur_len += 1
                cur += 1
            max_len = max(max_len, cur_len)
        return max_len

