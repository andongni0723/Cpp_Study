from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left_max = [0] * n
        left_max[0] = height[0]
        ans = 0
        for i in range(1, n):
            left_max[i] = max(left_max[i-1], height[i])

        right_max = 0
        for i in range(n-1, -1, -1):
            right_max = max(right_max, height[i])
            ans += min(left_max[i], right_max) - height[i]
        return ans