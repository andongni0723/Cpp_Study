from typing import Optional
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast is slow: # is cycling
                fast = head
                while fast is not slow:
                    fast = fast.next
                    slow = slow.next
                return fast # found entrance
        return None