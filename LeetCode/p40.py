from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []
        n = len(candidates)
        candidates.sort()

        def dfs(idx: int, t: int) -> None:
            if t == 0:
                ans.append(path.copy())
                return

            if idx == len(candidates) or t < candidates[idx]: return

            # choose
            path.append(candidates[idx])
            dfs(idx + 1, t - candidates[idx])
            path.pop()  # backtracking

            # not choose
            next = idx + 1
            while next < n and candidates[next] == candidates[idx]:
                next += 1
            dfs(next, t)


        dfs(0, target)
        return ans