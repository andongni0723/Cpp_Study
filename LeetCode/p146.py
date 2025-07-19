class LinkNode:
    def __init__(self, key = 0, val = 0, prev = None, next = None):
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = LinkNode(-1, -1) # dummy start
        self.tail = LinkNode(-2, -2) # dummy end
        self.head.next = self.tail
        self.tail.prev = self.head
        self.cache = {}               # key: LinkNode

    def get(self, key: int) -> int:
        node = self.cache.get(key)
        if not node: return -1
        self._move_node_to_tail(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        node = self.cache.get(key)
        if node:  # exist
            node.val = value
            self._move_node_to_tail(node)
        else:
            if len(self.cache) == self.capacity:  # full
                first = self.head.next
                self._remove_node(first)
                del self.cache[first.key]

            new_node = LinkNode(key, value)
            self.cache[key] = self._new_node_before_tail(new_node)

    def _remove_node(self, node: LinkNode) -> None:
        node.prev.next = node.next
        node.next.prev = node.prev

    def _new_node_before_tail(self, node: LinkNode) -> LinkNode:
        tail_prev = self.tail.prev
        tail_prev.next = node
        node.next = self.tail
        node.prev = tail_prev
        self.tail.prev = node
        return node

    def _move_node_to_tail(self, node: LinkNode) -> None:
        self._remove_node(node)
        self._new_node_before_tail(node)