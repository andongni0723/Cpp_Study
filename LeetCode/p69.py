class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = -1, x+1
        while l + 1 < r:
            mid = (l+r) // 2
            if mid ** 2 == x:
                return mid
            elif mid ** 2 < x:
                l = mid
            else:
                r = mid
        return l