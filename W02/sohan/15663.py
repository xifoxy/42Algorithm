N, M = map(int, input().split(' '))
arr = sorted(list(map(int, input().split(' '))))
per = [0 for i in range(N)]
visited = [0 for i in range(N)]
before = set()
current = []

def permutation(cnt):
  global before
  global current
  if cnt == M:
    for i in range(M):
      current.append(per[i])
      
    before.add(tuple(current))
    current = []
    return
  for i in range(N):
    if not visited[i]:
      visited[i] = True
      per[cnt] = arr[i]
      permutation(cnt + 1)
      visited[i] = False

permutation(0)
for _ in sorted(before):
  print(*_, sep=' ')