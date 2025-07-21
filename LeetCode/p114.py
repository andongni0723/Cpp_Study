from prelude import *
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        if root is None: return None
        self.flatten(root.left)
        self.flatten(root.right)
        if not root.left: return
        right = root.right
        root.right = root.left
        root.left = None
        cur = root.right
        while cur.right:
            cur = cur.right
        cur.right = right