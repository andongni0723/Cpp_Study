from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def depth(self, tree: Optional[TreeNode]) -> int:
        if tree is None: return 0
        left  = self.depth(tree.left)
        right = self.depth(tree.right)
        self.max_ans = max(self.max_ans, left + right)
        return max(left, right) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_ans = 0
        self.depth(root)
        return self.max_ans
