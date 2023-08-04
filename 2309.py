from itertools import combinations
hobits = sorted([int(input()) for _ in range(9)])
seven_out_of_nine = combinations(hobits, 7)
for combi in seven_out_of_nine:
  ans = sum(combi)
  if ans == 100:
    print(*combi, sep="\n")
    break