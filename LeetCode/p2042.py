from typing import List

class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        prev = -1
        cur  = []

        def check() -> bool:
            nonlocal prev, cur
            if not cur:
                return True
            num = int(''.join(cur))
            if num <= prev:
                return False
            prev = num
            cur.clear()
            return True

        for c in s:
            if c.isdigit():
                cur.append(c)
            else:
                if not check():
                    return False

        return check()