#include <cstdio>

const int SZ = 5e2 + 1;
int dp[SZ][SZ];
int n;

int max(int a, int b) { return a > b ? a : b; }

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= i; ++j)
      scanf("%d", dp[i] + j);

  for (int i = n - 1; i > 0; --i)
    for (int j = 0; j < i; ++j)
      dp[i - 1][j] += max(dp[i][j], dp[i][j + 1]);

  printf("%d\n", **dp);
}

// 아래서부터 위로 갱신해가면 쉽다.
// 위에서부터 아래로 갔는데 코드를 짜다보니
// 역순으로 하는게 조건도 더 단조롭고 코드도 보기 좋다.