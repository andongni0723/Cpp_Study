from prelude import *
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        min_val = root.val
        sec_val = inf
        def dfs(node: Optional[TreeNode]):
            if node is None: return
            nonlocal min_val, sec_val
            if node.val >= sec_val: return
            if node.val > min_val:
                sec_val = node.val
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return sec_val if sec_val != inf else -1