from collections import Counter
from math import inf
from typing import List

class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        plate = [c.lower() for c in licensePlate if c.isalpha()]
        need = Counter(plate)
        min_word = ''
        for w in words:
            time = Counter(w)
            is_completing = True
            for char, count in need.items():
                if time[char] < count:
                    is_completing = False
                    break
            if is_completing:
                if not min_word or len(w) < len(min_word):
                    min_word = w
        return min_word