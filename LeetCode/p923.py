from typing import List
from math import *
from collections import Counter

class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        seem = Counter(arr)
        arr_set = sorted(seem)
        n = len(arr_set)
        ans = 0
        for i in range(n):
            a = arr_set[i]
            for j in range(i, n):
                b = arr_set[j]
                c = target - a - b
                if c < b:continue
                if c not in arr_set: continue
                if a == b == c:
                    ans += comb(seem[a], 3)
                elif a == b < c:
                    ans += comb(seem[a], 2) * seem[c]
                elif a < b == c:
                    ans += comb(seem[b], 2) * seem[a]
                else:
                    ans += seem[a] * seem[b] * seem[c]
        return ans % (10**9 + 7)