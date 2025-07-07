from collections import Counter
from typing import List

class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        max_x = max(deliciousness)
        power = [1<< i for i in range((max_x*2).bit_length())]
        seem = Counter()
        result = 0
        for x in deliciousness:
            for p in power:
                y = p - x
                result += seem[y]
            seem[x] = seem[x] + 1

        return result % (10**9 + 7)