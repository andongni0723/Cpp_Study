# Definition for a binary tree node.
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        visited = [False] * (10**4 + 1)
        result = 0

        def dfs(node) -> int:
            nonlocal result
            if not node: return 0
            l, r = dfs(node.left), dfs(node.right)
            result += abs(l - r)
            return l + r + node.val

        dfs(root)
        return result


