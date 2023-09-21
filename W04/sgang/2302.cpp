#include <cstdio>

const int SZ = 41;
int arr[SZ];
int dp[SZ]{1, 1};
int ans = 1;
int n, visitor, idx;

int main() {
  for (int i = 2; i < 41; ++i)
    dp[i] = dp[i - 1] + dp[i - 2];

  scanf("%d%d", &n, &visitor);

  for (int i = 0; i < visitor; ++i) {
    scanf("%d", &idx);
    arr[idx] = -1;
  }

  for (int i = 1; i <= n; ++i) {
    if (arr[i] != -1) {
      arr[i] = arr[i - 1] + 1;
      continue;
    }
    arr[i] = 0;
    ans *= dp[arr[i - 1]];
  }

  if (arr[n] != 0)
    ans *= dp[arr[n]];
  printf("%d\n", ans);
}

// 1. 앉을 수 있는 자리의 경우의 수를 구한다.
// VIP좌석을 기준으로 값을 곱해주면 모드는 경우를 구할 수 있다.