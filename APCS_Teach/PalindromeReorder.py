from collections import Counter

n = input()
seem = Counter(n)
one = "".join(i for i in seem if seem[i] & 1)
ans = ""
stack = []
sorted(seem).reverse()
if len(one) > 1:
    print("NO SOLUTION")
else:
    for i in seem:
        ans += i * int(seem[i]//2)
        stack.append(i)
    ans += one
    while stack:
        c = stack.pop()
        ans += c * int(seem[c]//2)
print(ans)