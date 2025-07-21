from prelude import *
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        stack = [inf]
        cost = 0
        for num in arr:
            while num > stack[-1]:
                mid = stack.pop()
                cost += mid * min(num, stack[-1])
            stack.append(num)
        while len(stack) > 2:
            mid = stack.pop()
            cost += mid * stack[-1]
        return cost

class Solution2:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        mx = [[0] * n for _ in range(n)]
        for i in range(n):
            mx[i][i] = arr[i]
            for j in range(i+1, n):
                mx[i][j] = max(mx[i][j-1], arr[j])

        dp = [[0] * n for _ in range(n)]
        for length in range(2, n+1):
            for i in range(0, n+1-length):
                j = i = length - 1
                dp[i][j] = inf
                for k in range(i, j):
                    cost = dp[i][k] + dp[k+1][j] + mx[i][k] * mx[k+1][j]
                    if cost < dp[i][j]:
                        dp[i][j] = cost

a = [6, 2, 4, 5] # ans  = 58
print(Solution2().mctFromLeafValues(a))