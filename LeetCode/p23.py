# Definition for singly-linked list.
from heapq import *
from typing import *
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = [(node.val, id(node), node) for node in lists if node]
        head = ListNode()
        cur = head
        heapify(heap) # node.val id(node) node

        while heap:
            val, _, node = heappop(heap)
            cur.next = node
            cur = cur.next
            if node.next:
                heappush(heap, (node.next.val, id(node.next), node.next))

        return head.next

