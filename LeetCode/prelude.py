import sys
import os
import math
import random
import time
import re
import json
from decimal import Decimal, getcontext
from math import inf

from collections import deque, Counter, defaultdict, namedtuple
import heapq
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right

from typing import List, Dict, Set, Tuple, Optional, Union, Any

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        # 方便打印鏈結串列
        vals = []
        curr = self
        while curr:
            vals.append(str(curr.val))
            curr = curr.next
        return " -> ".join(vals)

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f"TreeNode(val={self.val}, left={self.left}, right={self.right})"


def string_to_listnode(s: str) -> Optional[ListNode]:
    """將 '[1,2,3]' 格式的字串轉為鏈結串列"""
    try:
        nums = json.loads(s)
        if not nums:
            return None
        head = ListNode(nums[0])
        curr = head
        for i in range(1, len(nums)):
            curr.next = ListNode(nums[i])
            curr = curr.next
        return head
    except:
        return None