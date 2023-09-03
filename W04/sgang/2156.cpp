#include <cstdio>

const int SZ = 1e4 + 1;
int dp[SZ];
int arr[SZ];
int n;

int max(int a, int b) { return a > b ? a : b; }

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i)
    scanf("%d", arr + i);

  dp[1] = arr[1];
  dp[2] = dp[1] + arr[2];

  for (int i = 3; i <= n; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    dp[i] = max(dp[i], dp[i - 3] + arr[i] + arr[i - 1]);
  }

  printf("%d\n", dp[n]);
}

// 계단문제와 유사하다. 하지만 다른점이 하나있다.