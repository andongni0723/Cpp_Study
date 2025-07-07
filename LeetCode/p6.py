class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        result = [""]*numRows
        cur = 0
        dir = 1 # 1: down, -1: up
        for c in s:
            if cur == 0:
                dir = 1
            if cur == numRows -1 :
                dir = -1

            result[cur] += c
            cur += dir


        return "".join(result)