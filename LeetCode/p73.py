from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        is_first_row_zero = is_first_column_zero = False
        m, n = len(matrix), len(matrix[0])

        for y in range(m):
            if matrix[y][0] == 0: is_first_column_zero = True
        for x in range(n):
            if matrix[0][x] == 0: is_first_row_zero = True

        for y in range(1, m):
            for x in range(1, n):
                if matrix[y][x] == 0:
                    matrix[y][0] = 0
                    matrix[0][x] = 0
        for y in range(1, m):
            for x in range(1, n):
                if matrix[y][0] == 0 or matrix[0][x] == 0:
                    matrix[y][x] = 0

        if is_first_row_zero:
            for x in range(n):
                matrix[0][x] = 0
        if is_first_column_zero:
            for y in range(m):
                matrix[y][0] = 0