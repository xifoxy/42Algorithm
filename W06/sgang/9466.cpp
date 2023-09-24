#include <cstdio>
#include <cstring>

const int SZ = 1e5 + 1;

int adj[SZ];
bool dp[SZ];
bool visit[SZ];

int t, n, num, ans;

int sol(int current) {
  visit[current] = true;
  int next = adj[current];
  int ret = 0;

  // component를 이루고 있는 노드의 순회가 끝나면 else if로 들어간다.
  if (!visit[next])
    ret += sol(next);
  else if (!dp[next] && ++ret)
    // component를 이루고 있는 노드의 갯수 카운트
    for (int index = next; index != current; index = adj[index])
      ++ret;

  dp[current] = true;
  return ret;
}

int main() {
  scanf("%d", &t);

  while (t--) {
    ans = 0;
    memset(visit, false, sizeof(visit));
    memset(dp, false, sizeof(dp));
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
      scanf("%d", adj + i);

    for (int i = 1; i <= n; ++i)
      if (!visit[i])
        ans += sol(i);

    printf("%d\n", n - ans);
  }
}

// 예전에 푼 흔적이 있길래 해석을 2가지를 남겨야 할것 같다.

// solution. 1(기존에 풀었던 방식)
// 문제를 잘 살펴보면, dp을 이루지 못하는 노드의 갯수를 구하는걸 요구한다.
// 그럼 여기서 가지고 놀 수 있는 기재가 하나 있는데 indegree다.
//   1. 입력받을때 각 노드의 indegree차수를 입력해준다.
//     - 예를들어 1->3 3->3 이면 3의 indegree는 2가 된다.
//   2. indegree가 없는 node를 기준으로 재귀를 태운다.
//   3. node가 가르키는 next node의 indegree의 차수를 줄여주고,
//   4. 현재 기준 노드를 가지고 2번으로 돌아간다.

// solution. 2
// 발상을 바꿔 볼수 있다. solution. 1에서는 indegree차수를 가지고 놀았다면,
// solution. 2 에서는 component를 형성하는 노드의 갯수를 세서,
// 전체 노드에서 앞에서 구한 수를 빼면 답이 된다.