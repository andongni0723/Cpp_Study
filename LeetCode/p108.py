# Definition for a binary tree node.
from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def build(arr: List[int]) -> Optional[TreeNode]:
            if not arr: return None
            mid = (len(arr) - 1) // 2
            root = TreeNode(arr[mid])
            root.left = build(arr[:mid])
            root.right = build(arr[mid+1:])
            return root
        return build(nums)
