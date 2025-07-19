class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0': return '0'
        n, m = len(num1), len(num2)
        ans = [0] * (n + m)
        a = [int(i) for i in num1[::-1]]
        b = [int(i) for i in num2[::-1]]

        for i in range(n):
            for j in range(m):
                ans[i + j] += a[i] * b[j]

        carry = 0
        for i in range(len(ans)):
            ans[i] += carry
            carry, ans[i] = divmod(ans[i], 10)

        while len(ans) > 1 and ans[-1] == 0:
            ans.pop()

        return "".join(str(i) for i in ans[::-1])