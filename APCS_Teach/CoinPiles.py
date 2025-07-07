from sys import stdin, stdout
re = stdin.buffer.readline

n = int(re())
arr = [list(map(int, re().split())) for _ in range(n)]

for l, r in arr:
    stdout.write(("YES" if (l+r) % 3 == 0 and (l/2 <= r) and (r/2 <= l) else "NO") + '\n')