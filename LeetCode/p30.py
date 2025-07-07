from typing import List
from collections import Counter, defaultdict

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words: return []
        L = len(words[0])
        m = len(words)
        if len(s) < L*m : return []
        need = Counter(words)
        n = len(s)
        ans = []

        for offset in range(L):
            l = r = offset
            current = defaultdict(int)
            count = 0
            while r + L <= n:
                word = s[r : r + L]
                r += L
                if word in need:
                    current[word] += 1
                    count += 1
                    while current[word] > need[word]:
                        left_word = s[l : l + L]
                        current[left_word] -= 1
                        count -= 1
                        l += L
                    if count == m:
                        print(offset)
                        ans.append(l)
                        left_word = s[l : l + L]
                        current[left_word] -= 1
                        count -= 1
                        l += L
                else:
                    count = 0
                    current.clear()
                    l = r
        return ans
