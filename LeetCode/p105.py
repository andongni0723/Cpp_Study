from prelude import *

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        n = len(preorder)
        inorder_idx_dict = {v: i for i, v in enumerate(inorder)}

        def build(pl: int, pr: int, il: int, ir: int) -> Optional[TreeNode]:
            if pl > pr: return None
            root_val = preorder[pl] 
            root = TreeNode(root_val)
            root_idx = inorder_idx_dict[root_val]
            left_len = root_idx - il
            root.left = build(pl + 1, pl + left_len, il, root_idx - 1)
            root.right = build(pl + left_len + 1, pr, root_idx + 1, ir)
            return root
        
        return build(0, n-1, 0, n-1)
        