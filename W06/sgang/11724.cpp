#include <iostream>
#include <vector>

using namespace std;

const int SZ = 1e3 + 1;

vector<int> adj[SZ];
int n, m;
int u, v, ans;
bool visit[SZ];

void dfs(int cur) {
  visit[cur] = true;
  for (auto &p : adj[cur])
    if (!visit[p])
      dfs(p);
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    if (visit[i])
      continue;
    dfs(i);
    ++ans;
  }

  cout << ans << '\n';
}

// 컴포넌트에 대한 기본 문제이다.
// 컴포넌트가 몇개 있는지 탐색만 잘해주면 된다.