from itertools import permutations

n = int(input())
signs = input().split()
m = None
for i in permutations(range(9, -1, -1), n+1):
    for j in range(n):
        if signs[j] == '<' and i[j] > i[j+1]:
            break
        elif signs[j] == '>' and i[j] < i[j+1]:
            break
    else:
        if m is None:
            print("".join(map(str, i)))
        m = i
print("".join(map(str, m)))

# 너무 바빠서 python 썼음...
# 9~0을 나열하는 경우의 수를 모두 탐색