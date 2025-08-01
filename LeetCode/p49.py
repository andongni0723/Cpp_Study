from collections import defaultdict
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        save = defaultdict(list)
        for s in strs:
            key = "".join(sorted(s))
            save[key].append(s)
        return list(save.values())