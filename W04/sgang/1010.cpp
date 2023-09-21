#include <cstdio>

const int SZ = 31;
int dp[SZ][SZ], tc, n, r;

int main() {
  for (int i = 0; i < SZ; ++i)
    dp[i][0] = 1;

  for (int i = 1; i < SZ; ++i)
    for (int j = 1; j <= i; ++j)
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

  scanf("%d", &tc);
  while (tc--) {
    scanf("%d%d", &r, &n);
    printf("%d\n", dp[n][r]);
  }
}

// 조합공식으로 풀리는 문제이다.