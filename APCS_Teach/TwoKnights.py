from itertools import count
from sys import stdin, stdout

n = int(stdin.readline())

# count "place two pieces" in chess
# (k^2)C2 = k^4 - k^2 / 2
for k in range(1, n+1):
    count = (k**4 - k**2) // 2
    attack = 4 * (k - 1) * (k - 2)
    stdout.write(str(count - attack) + '\n')