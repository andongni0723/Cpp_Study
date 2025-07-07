from sys import stdin, stdout

n = int(stdin.readline())

if n == 1:
    print(1)
elif n == 2 or n == 3:
    print("NO SOLUTION")
else:
    even = " ".join(str(i) for i in range(1, n + 1) if i % 2 == 0)
    odd = " ".join(str(i) for i in range(1, n + 1) if i % 2 == 1)
    stdout.write(f"{even} {odd}")