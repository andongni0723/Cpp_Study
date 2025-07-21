from collections import deque
from typing import Optional, List
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: return []
        ans = []
        queue = deque()
        queue.append(root)
        while queue:
            count = len(queue)
            current = []
            for _ in range(count):
                node = queue.popleft()
                current.append(node.val)
                if node.left:  queue.append(node.left)
                if node.right: queue.append(node.right)
            ans.append(current)
        return ans