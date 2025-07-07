from sys import *
re = stdin.readline

n = re()
arr = list(map(int, re().split()))
ans = max = 0
for i in arr:
    if i < max:
        ans += max - i
    else:
        max = i
print(ans)