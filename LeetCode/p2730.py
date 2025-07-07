class Solution(object):
    def longestSemiRepetitiveSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        l, max_size, same = 0, 1, 0

        for r in range(1, len(s)):
            if r > 0 and s[r] == s[r - 1]:
                same += 1

            while same > 1:
                if s[l + 1] == s[l]:
                    same -= 1
                l += 1

            max_size = max(max_size, r - l + 1)

        return max_size