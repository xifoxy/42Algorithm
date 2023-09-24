#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int SZ = 2e5 + 1;

int dp[SZ];

queue<int> Q;
int start, k;

bool safe(int x) { return x >= 0 && x < SZ && dp[x] == -1; }

int bfs() {
  dp[start] = 0;
  Q.push(start);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    if (cur == k)
      return dp[k];

    if (safe(cur * 2)) {
      Q.push(cur * 2);
      dp[cur * 2] = dp[cur] + 1;
    }
    if (safe(cur + 1)) {
      Q.push(cur + 1);
      dp[cur + 1] = dp[cur] + 1;
    }
    if (safe(cur - 1)) {
      Q.push(cur - 1);
      dp[cur - 1] = dp[cur] + 1;
    }
  }
  return 0;
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> start >> k;
  cout << bfs() << '\n';
}

// 요구사항에 맞게 이동만 잘 시켜주면 된다.