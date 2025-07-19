from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def merge_sort(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: return head
        right = self.middle(head)
        left = self.merge_sort(head)
        right = self.merge_sort(right)
        return self.merge(left, right)

    def middle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = prev = head
        while fast and fast.next:
            prev = slow
            fast = fast.next.next
            slow = slow.next
        prev.next = None
        return slow

    def merge(self, a: Optional[ListNode], b: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        cur = dummy
        while a and b:
            if a.val < b.val:
                cur.next = a
                a = a.next
            else:
                cur.next = b
                b = b.next
            cur = cur.next
        cur.next = a if a else b
        return dummy.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head: return None
        return self.merge_sort(head)


head = ListNode(4, ListNode(2, ListNode(1, ListNode(3))))
o = Solution().sortList(head)
print("---")
print(o)