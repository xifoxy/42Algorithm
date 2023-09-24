#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int SZ = 1e4 + 1;

struct info {
  int node, weight;
};

vector<info> adj[SZ];
int dp[SZ];
bool visit[SZ];
int n;

int dfs(int pos) {
  int ret = pos;
  visit[pos] = true;

  for (auto &p : adj[pos]) {
    if (visit[p.node])
      continue;

    dp[p.node] += dp[pos] + p.weight;
    int next = dfs(p.node);
    ret = dp[next] > dp[ret] ? next : ret;
  }

  return ret;
}

int main() {
  scanf("%d", &n);

  for (int i = 1; i < n; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int ans = dfs(1);
  memset(dp, 0, sizeof(dp));
  memset(visit, false, sizeof(visit));
  printf("%d\n", dp[dfs(ans)]);
}

// 엄청 복잡해보이지만 의외로 간단한 문제이다.
// 제일 처음 루트에서 가장 먼 노드를 찾아준다.
// 그리고 이 찾은 노드로 트리의 지름을 구해주면 최대 길이가 된다.