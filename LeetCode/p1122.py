from typing import List

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        return sorted(arr1, key=(arr2 + sorted(set(arr1) - set(arr2))).index)