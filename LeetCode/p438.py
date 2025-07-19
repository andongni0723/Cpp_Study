from collections import Counter, defaultdict
from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        need = Counter(p)
        cur = defaultdict(int)
        type_count = 0
        need_type_count = len(need)
        ans = []
        l = 0
        for r, c in enumerate(s):
            cur[c] += 1
            if cur[c] == need[c]:
                type_count += 1

            if type_count == need_type_count and r + 1 - l == len(p):
                ans.append(l)

            if r + 1 - l >= len(p):
                start_c = s[l]
                if cur[start_c] == need[start_c]:
                    type_count -= 1
                cur[start_c] -= 1
                l += 1
        return ans