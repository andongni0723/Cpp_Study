class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        match = {')':'(', ']':'[', '}':'{'}
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stack.append(i)
            else:
                if match[i] != stack.pop():
                    return False
        return len(stack) == 0