from collections import defaultdict
from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last = defaultdict(int)
        result = []
        start = right = 0

        for i in range(len(s)):
            last[s[i]] = i

        for i in range(len(s)):
            right = max(right, last[s[i]])
            if i == right:
                result.append(right - start + 1)
                start = i + 1
        return result