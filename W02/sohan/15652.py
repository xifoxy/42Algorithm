N, M = map(int, input().split(' '))
arr = [i + 1 for i in range(N)]
comb = [0 for i in range(N)]

def combination_repetitive(idx ,cnt):
  if cnt == M:
    for idx in range(M):
      print(comb[idx], end=" ")
    print("") 
    return
  for i in range(idx, len(arr)):
    comb[cnt] = arr[i]
    combination_repetitive(i, cnt + 1)

combination_repetitive(0, 0)
