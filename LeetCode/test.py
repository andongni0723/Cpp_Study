from sys import stdin

# n = list(map(int, stdin.readline().split()))
# n = list(map(int, stdin.readlines()))
# n = list(map(int, input().split()))
s = input()

split = ""
l = 0
for r in range(len(s) - 1):
    if r != 0:
        if len(split) >= 3:
            l += 1

        split = s[l:r+1]


    print(split)