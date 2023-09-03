#include <cstdio>

const int SZ = 1e6 + 1;
int dp[SZ];
int n;

int min(int a, int b) { return a > b ? b : a; }

int main() {
  scanf("%d", &n);

  for (int i = 2; i <= n; ++i) {
    ++dp[i] += dp[i - 1];
    if (i % 2 == 0)
      dp[i] = min(dp[i / 2] + 1, dp[i]);
    if (i % 3 == 0)
      dp[i] = min(dp[i / 3] + 1, dp[i]);
  }
  printf("%d\n", dp[n]);
}

// 주어진 공식대로 점화식을 만들면 된다.