from itertools import groupby

class Solution:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        n = len(s)
        start = 0
        for i in range(1, n+1):
            if i < n and s[i] == s[i-1]: continue
            length = i - start
            if length == k:
                left = start == 0 or s[start - 1] != s[start]
                right = i == n or s[i] != s[start]
                if left and right:
                    return True
            start = i
        return False

class Solution2:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        for _, it in groupby(s):
            if len(list(it)) == k:
                return True
        return False