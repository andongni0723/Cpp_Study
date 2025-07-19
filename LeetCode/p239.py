from collections import defaultdict, deque
from heapq import heappush, heappop
from typing import List

# O(n)
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k == 0: return []
        deq = deque() # idx
        ans = []
        for r, num in enumerate(nums):
            while deq and nums[deq[-1]] <= num:
                deq.pop()
            deq.append(r)
            if deq[0] <= r - k:
                deq.popleft()
            if r >= k - 1:
                ans.append(nums[deq[0]])
        return ans


# O(n log n)
class Solution2:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        seem = defaultdict(int)
        max_heap = [] # (-num)
        ans = []
        l = 0
        for r, num in enumerate(nums):
            heappush(max_heap, -num)
            seem[num] += 1
            if r >= k-1:
                find = False
                while not find:
                    max_num = heappop(max_heap)
                    max_num = -max_num
                    if seem.get(max_num, 0) > 0:
                        ans.append(max_num)
                        find = True
                        heappush(max_heap, -max_num)
                seem[nums[l]] -= 1
                l += 1
        return ans

l = [1,3,-1,-3,5,3,6,7]
ans = [3,3,5,5,6,7]
a = Solution().maxSlidingWindow(l, 3)
print('---')
print(a)
print(ans)
print(Solution().maxSlidingWindow(l, 3) == ans)