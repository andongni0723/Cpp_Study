from typing import List
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def f(l=0, r=0, res=''):
            if len(res) == 2 * n:
                ans.append(res)
                return
            if l < n:
                f(l+1, r, res + '(')
            if r < n and r < l:
                f(l, r+1, res + ')')
        f()
        return ans