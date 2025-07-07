from typing import List
class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        if len(words) != len(s): return False
        for i, f in enumerate(s):
            print(i, f, words[i])
            if not words[i].startswith(f):
                return False
        return True