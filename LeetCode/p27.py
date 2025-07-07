class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        l = 0
        for r in range(len(haystack)+1):
            if len(haystack[l:r]) >= len(needle):
                if haystack[l:r] == needle: return l
                l += 1
        return -1