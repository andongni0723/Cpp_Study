from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []
        candidates.sort()

        def dfs(idx: int, t: int) -> None:
            if t == 0:
                ans.append(path.copy())
                return

            if idx == len(candidates) or t < candidates[idx]: return

            dfs(idx + 1, t)

            path.append(candidates[idx])
            dfs(idx, t - candidates[idx])
            path.pop()  # backtracking

        dfs(0, target)
        return ans