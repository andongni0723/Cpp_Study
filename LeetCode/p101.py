from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def is_same(self, a: Optional[TreeNode], b: Optional[TreeNode]) -> bool:
        if a is None or b is None: return a is b
        return a.val == b.val and self.is_same(a.left, b.right) and self.is_same(a.right, b.left)
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None: return True
        return self.is_same(root.left, root.right)