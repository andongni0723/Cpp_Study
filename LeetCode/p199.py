from prelude import *

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None: return []
        queue = deque()
        queue.append(root)
        ans = []
        while queue:
            n = len(queue)
            for i in range(n):
                node = queue.popleft()
                if i == n-1: ans.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
        return ans