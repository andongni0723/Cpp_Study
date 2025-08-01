from collections import Counter
class Solution:
    def equalFrequency(self, word: str) -> bool:
        for i in range(len(word)):
            if len(set(Counter(word[:i] + word[i+1:]).values())) == 1:
                return True
        return False