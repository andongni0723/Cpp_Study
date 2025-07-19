from sympy import factorial


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = list(range(1, n + 1))
        k -= 1
        ans = []
        for i in range(1, n + 1):
            fact = factorial(n - i)
            idx = k // fact
            ans.append(nums[idx])
            nums.pop(idx)
            k %= fact
        return "".join(map(str, ans))
