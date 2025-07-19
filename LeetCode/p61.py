from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0: return head
        nodes = []
        cur = head
        while cur:
            nodes.append(cur)
            cur = cur.next
        n = len(nodes)
        k %= n
        if k == 0: return head
        new_head, new_tail, tail = nodes[-k], nodes[-k-1], nodes[-1] # 4 -> 5, 3 -> 4 -> 5, 5 -> None
        new_tail.next = None # 3 -> None
        tail.next = head # 5 -> 1 -> 2 -> ...
        return new_head # 4 -> 5 -> 1 -> ...