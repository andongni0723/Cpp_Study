class Solution:
    def simplifyPath(self, path: str) -> str:
        paths = path.split('/')
        stack = []
        for p in paths:
            if p == '' or p == '.': continue
            if p == '..':
                if stack: stack.pop()
            else:
                stack.append('/' + p)
        return ''.join(stack) if stack else '/'