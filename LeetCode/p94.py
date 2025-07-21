# Definition for a binary tree node.
from typing import Optional, List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Bottom-up
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            tree = stack.pop()
            ans.append(tree.val)
            root = tree.right
        return ans


# Top-down
class Solution2:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def dfs(tree: TreeNode):
            if tree is None: return
            dfs(tree.left)
            ans.append(tree.val)
            dfs(tree.right)
        dfs(root)
        return ans