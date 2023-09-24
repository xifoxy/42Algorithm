#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int SZ = 1e3 + 1;

vector<int> adj[SZ];
queue<int> Q;
int n, m, root;
int u, v;
bool visit[SZ];
string ans;

void dfs(int cur) {
  visit[cur] = true;
  ans += to_string(cur) + ' ';
  for (auto &p : adj[cur])
    if (!visit[p])
      dfs(p);
}

void bfs() {
  memset(visit, 0, sizeof(visit));
  ans += "\n" + to_string(root);
  Q.push(root);
  visit[root] = true;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (auto &p : adj[cur]) {
      if (visit[p])
        continue;

      visit[p] = true;
      ans += ' ' + to_string(p);
      Q.push(p);
    }
  }
}

int main() {
  cin >> n >> m >> root;

  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < SZ; ++i)
    sort(adj[i].begin(), adj[i].end());

  dfs(root);
  bfs();
  cout << ans << '\n';
}

// 그래프탐색 기초 문제