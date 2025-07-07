class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0: return []
        letter_num = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }
        res = []
        def add(idx, string):
            if idx == len(string):
                res.append(string)
                return
            for c in letter_num[digits[idx]]:
                add(idx + 1, string + c)
        add(0, '')
        return res