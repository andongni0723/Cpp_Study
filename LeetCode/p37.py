from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        self.row = [[False] * 10 for _ in range(9)]
        self.col = [[False] * 10 for _ in range(9)]
        self.grid = [[False] * 10 for _ in range(9)]
        self.space = []

        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    self.space.append((i, j))
                else:
                    num = int(board[i][j])
                    block = (i // 3) * 3 + j // 3
                    self.row[i][num] = self.col[j][num] = self.grid[block][num] = True

        self.backtrack(board, 0)

    def backtrack(self, board: List[List[str]], idx: int) -> bool:
        if idx == len(self.space): return True
        i, j = self.space[idx]
        block = (i // 3) * 3 + j // 3

        # find numbers can fill in
        candidates = []
        for num in range(1, 10):
            if not (self.row[i][num] or self.col[j][num] or self.grid[block][num]):
                candidates.append(num)

        for num in candidates:
            # update data
            self.row[i][num] = self.col[j][num] = self.grid[block][num] = True
            board[i][j] = str(num)

            # result is correct
            if self.backtrack(board, idx + 1): return True

            # incorrect, backtracking
            self.row[i][num] = self.col[j][num] = self.grid[block][num] = False
            board[i][j] = '.'

        return False