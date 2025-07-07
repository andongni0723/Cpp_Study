n = int(input())

set1 = []
set2 = []

if n % 4 == 0:
    for i in range(1, n+1, 4):
        set1.append(i)
        set1.append(i+3)
        set2.append(i+1)
        set2.append(i+2)

elif n % 4 == 3:
    set1.append(1)
    set1.append(2)
    set2.append(3)
    for i in range(4, n+1, 4):
        set1.append(i)
        set1.append(i + 3)
        set2.append(i + 1)
        set2.append(i + 2)

if set1:
    print("YES")
    print(len(set1))
    print(" ".join(str(i) for i in set1))
    print(len(set2))
    print(" ".join(str(i) for i in set2))
else:
    print("NO")