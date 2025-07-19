class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # dp[i][j] is match string with s[:i] and p[:j]
        n, m = len(s), len(p)
        dp = [[False] * (m + 1) for _ in range(n + 1)]

        # case: string and pattern is empty
        dp[0][0] = True

        # case: string is empty, pattern must all be '*'
        for j in range(1, m + 1):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-1]

        # normal case
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if p[j-1] == '*':
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                elif p[j-1] == '?' or s[i-1] == p[j-1]:
                    dp[i][j] = dp[i-1][j-1]

        return dp[n][m]