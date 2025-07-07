from networkx.utils.misc import pairwise


class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }

        res = 0
        for x, y in pairwise(s):
            nx, ny = roman[x], roman[y]
            res += nx if nx >= ny else -nx
        return res + roman[s[-1]]
