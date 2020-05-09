import math

for i in range(int(input())):
    num = int(input())
    a = [int(x) for x in input().split()]
    final = math.ceil(num/2 - a.index(max(a)) - 1)
    print(a[::-1].index(max(a)) - final)
