N, M = map(int, input().split(' '))
arr = sorted(list(map(int, input().split(' '))))
per = [0 for i in range(N)]

def combination_repetitive(idx, cnt):
  if cnt == M:
    for i in range(M):
      print(per[i], end=" ")
    print("") 
    return
  for i in range(idx, N):
      per[cnt] = arr[i]
      combination_repetitive(i, cnt + 1)

combination_repetitive(0, 0)