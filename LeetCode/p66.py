from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = True
        p = len(digits)
        ans = [0] * (len(digits) + 1)
        for i in range(len(digits)):
            ans[i+1] = digits[i]
        print(ans)
        while carry:
            carry = False
            ans[p] += 1
            if ans[p] == 10:
                ans[p] = 0
                carry = True
                p -= 1
        return ans if ans[0] == 1 else ans[1:]