N, M = map(int, input().split(' '))
arr = sorted(list(map(int, input().split(' '))))
per = [0 for i in range(N)]
visited = [0 for i in range(N)]

def permutation(cnt):
  if cnt == M:
    for idx in range(M):
      print(per[idx], end=" ")
    print("") 
    return
  for i in range(N):
    if not visited[i]:
      visited[i] = True
      per[cnt] = arr[i]
      permutation(cnt + 1)
      visited[i] = False

permutation(0)