N, M = map(int, input().split(' '))
arr = [i + 1 for i in range(N)]
visited = [0 for i in range(N)]

def combination(idx ,cnt):
  if cnt == M:
    for i in range(N):
      if visited[i]:
        print(arr[i], end=" ")
    print("") 
    return
  for i in range(idx, N):
    if visited[i]:
      continue
    visited[i] = True
    combination(i, cnt + 1)
    visited[i] = False

combination(0, 0)
