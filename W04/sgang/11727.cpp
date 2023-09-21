#include <cstdio>

const int SZ = 1e3 + 1;
const int MOD = 1e4 + 7;
int dp[SZ]{1, 1};
int n;

int main() {
  scanf("%d", &n);

  for (int i = 2; i <= n; ++i)
    dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;

  printf("%d\n", dp[n]);
}

// 이 문제는 한번 그려보면 경우를 구하기가 쉽다.