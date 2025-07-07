from typing import List
from collections import Counter
class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        seem = Counter(nums)
        return [i for i in seem if seem[i] == 2]