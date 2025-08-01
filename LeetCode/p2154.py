from typing import List

class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        while original in nums:
            original <<= 1
        return original