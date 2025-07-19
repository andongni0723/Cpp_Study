from typing import List

# O(log n)
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        if target < matrix[0][0] or target > matrix[m - 1][n - 1]: return False
        l, r = -1, m * n
        while l + 1 < r:
            mid = (l + r) // 2
            val = matrix[mid//n][mid%n]
            if val == target: return True
            if val < target: l = mid
            else: r = mid
        return False

# O(n log n)
class Solution2:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        if target < matrix[0][0] or target > matrix[m - 1][n - 1]: return False

        for y in range(m):
            if target > matrix[y][n - 1]: continue
            l, r = -1, n
            while l + 1 < r:
                mid = (l + r) // 2
                if matrix[y][mid] == target: return True
                if matrix[y][mid] < target: l = mid
                else: r = mid
            return matrix[y][r] == target
        return False