class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[None] * 40 for _ in range(40)]

        def f(i, j):
            print(i, j)
            if j < 0: return i < 0
            if dp[i][j] is not None: return dp[i][j]

            if p[j] == '*':
                char_match = i >= 0 and (s[i] == p[j-1] or p[j-1] == '.')
                dp[i][j] = f(i, j-2) or (char_match and f(i-1, j))
            else:
                char_match = i >= 0 and (s[i] == p[j] or p[j] == '.')
                dp[i][j] = char_match and f(i-1, j-1)

            return dp[i][j]

        return f(len(s) - 1, len(p) - 1)