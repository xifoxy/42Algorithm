from copy import deepcopy

n, m = input().split()
n, m = int(n), int(m)

arr = [list(input()) for _ in range(n)]
for i in range(n):
    for j in range(m):
        if ((i + j) % 2 == 1 and arr[i][j] == 'W') or\
                ((i + j) % 2 == 0 and arr[i][j] == 'B'):
            arr[i][j] = 1
        else:
            arr[i][j] = 0

dpt = deepcopy(arr)
for i in range(n):
    for j in range(1, 8):
        dpt[i][j] += dpt[i][j - 1]
    for j in range(8, m):
        dpt[i][j] += dpt[i][j - 1] - arr[i][j - 8]
dpt2 = deepcopy(dpt)
for i in range(m):
    for j in range(1, 8):
        dpt2[j][i] += dpt2[j - 1][i]
    for j in range(8, n):
        dpt2[j][i] += dpt2[j - 1][i] - dpt[j - 8][i]
mn = 64
for i in range(7, n):
    for j in range(7, m):
        mn = min(mn, min(dpt2[i][j], 64-dpt2[i][j]))
print(mn)

# 구한 곳은 또 안 구해도 됨
