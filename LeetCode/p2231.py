from heapq import heappush, heappop

class Solution:
    def largestInteger(self, num: int) -> int:
        even = []
        odd = []
        ans = ""
        for n in str(num):
            n = int(n)
            heappush(odd if n & 1 else even, -n)
        for n in str(num):
            n = int(n)
            ans += str(-heappop(odd if n & 1 else even))
        return int(ans)