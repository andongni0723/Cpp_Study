from sys import stdin, stdout

re = stdin.readline

n = int(re())
arr = [list(map(int, re().split())) for _ in range(n)]

for y, x in arr:
    lev = max(x, y)

    if lev % 2 == 1:
        if x == lev:
            val = lev ** 2 - y + 1
        else:
            val = (lev - 1) ** 2 + x
    else:
        if y == lev:
            val = lev ** 2 - x + 1
        else:
            val = (lev - 1) ** 2 + y

    stdout.write(str(val) + '\n')