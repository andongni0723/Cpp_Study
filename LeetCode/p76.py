from collections import Counter, defaultdict
from math import inf

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        m, n = len(s), len(t)
        if n > m: return ''
        need = Counter(t)
        current = defaultdict(int)
        start, l, min_len, valid, type_count = 0, 0, inf, 0, len(need)
        for r, c in enumerate(s):
            if c in need:
                current[c] += 1
                if current[c] == need[c]:
                    valid += 1

            while valid == type_count:
                new_len = r + 1 - l
                if new_len < min_len:
                    min_len = new_len
                    start = l
                start_char = s[l]
                if start_char in need:
                    if current[start_char] == need[start_char]:
                        valid -= 1
                    current[start_char] -= 1
                l += 1

        return s[start : start + min_len] if min_len != inf else ''


print(Solution().minWindow("ADOBECODEBANC","ABC"))