N, M = map(int, input().split(' '))
arr = sorted(list(set(map(int, input().split(' ')))))
per = [0 for i in range(N)]

def permutation_repetitive(cnt):
  if cnt == M:
    for idx in range(M):
      print(per[idx], end=" ")
    print("") 
    return
  for i in range(len(arr)):
      per[cnt] = arr[i]
      permutation_repetitive(cnt + 1)

permutation_repetitive(0)