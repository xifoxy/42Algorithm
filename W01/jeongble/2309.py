from itertools import combinations as cb

nanjang = [int(input()) for _ in range(9)]
for i in cb(nanjang, 7):
    if sum(i) == 100:
        for j in sorted(i):
            print(j)
        break

# 조합을 모두 구해주는 combinations 사용해봄
