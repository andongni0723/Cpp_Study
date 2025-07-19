from typing import List

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seem = []
        for n in arr:
            if n * 2 in seem or (n % 2 == 0 and n // 2 in seem):
              return True
            seem.append(n)
        return False