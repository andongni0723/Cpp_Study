# Definition for singly-linked list.
from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        first = ListNode()
        prev_tail = first
        cur = head
        while True:
            checker = cur
            for _ in range(k):
                if checker is None: return first.next
                checker = checker.next

            next_head = checker
            print(next_head)

            prev, node = next_head, cur
            while node != next_head:
                next = node.next
                node.next = prev
                prev = node
                node = next

            prev_tail.next = prev
            prev_tail = cur
            cur = next_head