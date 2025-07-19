from typing import List

# O(n)
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        x, y = n-1, 0
        while x >= 0 and y < m:
            if matrix[y][x] > target:
                x -= 1
            elif matrix[y][x] < target:
                y += 1
            else:
                return True
        return False


# O(n log n)
class Solution2:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        for y in range(m):
            if target < matrix[y][0]: break
            if target > matrix[y][-1]: continue
            l, r = -1, n
            while l + 1 < r:
                mid = (l + r) // 2
                if matrix[y][mid] == target:
                    return True
                elif matrix[y][mid] < target:
                    l = mid
                else:
                    r = mid
        return False