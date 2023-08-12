N, M = map(int, input().split(' '))
arr = [i + 1 for i in range(N)]
per = [0 for i in range(N)]

def permutation_repetitive(cnt):
  if cnt == M:
    for idx in range(M):
      print(per[idx], end=" ")
    print("") 
    return
  for idx in range(len(arr)):
    per[cnt] = arr[idx]
    permutation_repetitive(cnt + 1)

permutation_repetitive(0)
