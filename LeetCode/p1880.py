class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        def f(s):
            return int("".join(str(ord(i) - ord('a')) for i in s))
        return f(targetWord) == f(firstWord) + f(secondWord)