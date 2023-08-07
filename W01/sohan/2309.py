# 9개중에 7개 전부 골라서 처음 합이 100이 되는게 있으면 출력하고 끝냄
# 처음에 sort 한거는 문제 이해를 잘못하고 한건데 이 풀이에 영향이 있는지는 모르겠음. 거꾸로 하면 더 빨리 되려나?
from itertools import combinations
hobits = sorted([int(input()) for _ in range(9)])
seven_out_of_nine = combinations(hobits, 7)
for combi in seven_out_of_nine:
  ans = sum(combi)
  if ans == 100:
    print(*combi, sep="\n")
    break