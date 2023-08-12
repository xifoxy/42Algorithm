N, M = map(int, input().split(' '))
arr = sorted(list(map(int, input().split(' '))))
per = [0 for i in range(N)]
visited = [0 for i in range(N)]
before = []
current = []
ans = []

def combination_repetitive(idx, cnt):
  global before
  global current
  if cnt == M:
    for i in range(M):
      current.append(per[i])
      
    if current not in before:
        print(*current, sep=' ')
        before.append(current)
    current = []
    return
  for i in range(idx, len(arr)):
      if not visited[i]:
        visited[i] = True
        per[cnt] = arr[i]
        combination_repetitive(i, cnt + 1)
        visited[i] = False

combination_repetitive(0, 0)