class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1: return '1'
        return self.rle(self.countAndSay(n-1))

    def rle(self, s: str) -> str:
        res = ''
        cur = 0
        for i, c in enumerate(s):
            cur += 1
            if i == 0: continue
            if c != s[i-1]:
                res += str(cur-1) + s[i-1]
                cur = 1
        if cur != 0:
            res += str(cur) + s[-1]
        return res
