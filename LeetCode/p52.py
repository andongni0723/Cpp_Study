from typing import List

class Solution:
    def totalNQueens(self, n: int) -> int:
        ans = 0
        save = [-1] * n
        used_cols = set()
        used_left_diags = set()
        used_right_diags = set()
        def backtrack(row):
            nonlocal ans
            if row == n:
                ans += 1
            for col in range(n):
                if(
                    col in used_cols
                    or (row - col) in used_left_diags
                    or (row + col) in used_right_diags
                ): continue
                save[row] = col
                used_cols.add(col)
                used_left_diags.add(row - col)
                used_right_diags.add(row + col)
                backtrack(row + 1)

                used_cols.remove(col)
                used_left_diags.remove(row - col)
                used_right_diags.remove(row + col)

        backtrack(0)
        return ans