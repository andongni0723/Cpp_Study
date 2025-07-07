# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def swap(node = head):
            if node is None: return None
            if node.next is not None:
                t1 = ListNode(node.val)
                t2 = ListNode(node.next.val)
                other = None if node.next.next is None else node.next.next
                t2.next = t1
                t1.next = swap(other)
                return t2
            else:
                return node
        return swap()
