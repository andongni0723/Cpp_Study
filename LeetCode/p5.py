class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1: return s
        bestL = bestR = 0

        def check_expand(l, r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return l+1, r-1

        for i in range(len(s)):
            l1, r1 = check_expand(i, i)
            l2, r2 = check_expand(i, i+1)

            if r1 - l1 > bestR - bestL:
                bestL, bestR = l1, r1
            if r2 - l2 > bestR - bestL:
                bestL, bestR = l2, r2

        return s[bestL:bestR+1]