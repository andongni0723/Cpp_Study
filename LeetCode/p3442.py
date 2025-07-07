from collections import  Counter

class Solution:
    def maxDifference(self, s: str) -> int:
        freq = Counter(s)
        max_odd, min_even = 0, float('INF')
        for i in freq:
            print(freq[i])
            if freq[i] % 2 == 1:
                max_odd = max(max_odd, freq[i])
            else:
                min_even = min(min_even, freq[i])

        return max_odd - min_even



