from prelude import *
class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        m, n = len(nums), len(nums[0])
        max_heap_arr = [[] * n for _ in range(m)]
        for row in range(m):
            for num in nums[row]:
                heappush(max_heap_arr[row], -num)

        ans = 0
        for i in range(n):
            cost = 0
            for max_heap in max_heap_arr:
                num = heappop(max_heap)
                num = -num
                cost = max(num, cost)
            ans += cost
        return ans


class Solution2:
    def matrixSum(self, nums: List[List[int]]) -> int:
        return sum(map(max, zip(*sorted, nums)))


a = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]] # ans = 15
print(Solution().matrixSum(a))

