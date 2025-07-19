# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# O(n), O(n)
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        vals = []
        cur = head
        while cur:
            vals.append(cur.val)
            cur = cur.next

        l, r = 0, len(vals) - 1
        for i in range(len(vals)//2):
            if vals[l] != vals[r]: return False
            l += 1
            r -= 1
        return True