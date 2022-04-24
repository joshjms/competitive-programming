n = int(input())
p = list(map(int, input().split()))
q = list(map(int, input().split()))

v = [False for i in range(n + 1)]

for i in range(1, p[0] + 1):
    v[p[i]] = True

for i in range(1, q[0] + 1):
    v[q[i]] = True

ans = True

for i in range(1, n + 1):
    ans = ans and v[i]

if ans == True:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")