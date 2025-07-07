from cmath import sqrt


class Solution:
    def countTriples(self, n: int) -> int:
        res = 0
        for i in range(1, n):
            for j in range(1, n):
                k = int(sqrt(i*i + j*j))
                if k <= n and i*i + j*j == k*k:
                    res += 1

        return res
