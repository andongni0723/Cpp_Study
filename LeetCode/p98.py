from prelude import *
class Solution:
    def isValidBST(self, root: Optional[TreeNode], left: int = -inf, right: int = inf) -> bool:
        if root is None: return True
        val = root.val
        return left < val < right \
               and self.isValidBST(root.left, left, val) \
               and self.isValidBST(root.right, val, right)