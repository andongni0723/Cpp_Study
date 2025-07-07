from sys import stdin, stdout
n = int(stdin.buffer.readline())

def gray(x):
    return x ^ (x >> 1)

for i in range(2**n):
    g = bin(gray(i))[2:]
    stdout.write('0' * max(0, n - len(g)) + g + '\n')