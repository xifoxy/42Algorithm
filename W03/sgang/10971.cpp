#include <cstdio>

const int INF = 1e9;
const int SZ = 10;

int n;
int a[SZ][SZ];
bool vst[SZ];

int min(int a, int b) { return a > b ? b : a; }

int sol(int dep, int sum, int cur) {
  if (dep == n - 1) {
    if (!a[cur][0])
      return INF;
    return sum + a[cur][0];
  }

  int ret = INF;
  for (int i = 0; i < n; ++i) {
    if (vst[i] || !a[cur][i])
      continue;
    vst[i] = true;
    ret = min(ret, sol(dep + 1, sum + a[cur][i], i));
    vst[i] = false;
  }

  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &a[i][j]);
  vst[0] = true;
  printf("%d\n", sol(0, 0, 0));
}

// 학상 순회할 수 있는 비용으로 주어지기 때문에 모든 경우를 다 찾아 보면된다.
// 문제에 백트레킹적 요소가 있는데,
// 방문한 경우와 방문할 수 있는 경우만 고려하면 된다.