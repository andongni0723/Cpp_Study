from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row  = [[0]*10 for _ in range(10)]
        col  = [[0]*10 for _ in range(10)]
        grid = [[0]*10 for _ in range(10)]
        for i in range(1, 10):
            for j in range(1, 10):
                if board[i-1][j-1] == '.': continue
                num = int(board[i-1][j-1])
                cur_grid = ((i-1) // 3) * 3 + ((j-1) // 3) + 1
                if row[i][num] or col[j][num] or grid[cur_grid][num]:
                    return False
                else:
                    row[i][num] = col[j][num] = grid[cur_grid][num] = 1
        return True