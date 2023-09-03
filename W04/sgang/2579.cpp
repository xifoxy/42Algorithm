#include <cstdio>

const int SZ = 3e2 + 1;
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

  for (int i = 3; i <= n; ++i)
    dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1]);

  printf("%d\n", dp[n]);
}

// 기저단위를 설정해주고
// 규칙에 맞게 max함수를 이용해서 계속 갱신하면 된다.
// 바로 전 단계 계단을 밟은 경우 그리고 전전 단계 계단을 밟은 경우