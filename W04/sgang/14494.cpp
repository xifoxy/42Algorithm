#include <cstdio>

const int SZ = 1e3 + 1;
const int MOD = 1e9 + 7;
unsigned int dp[SZ][SZ];
int n, m;

int main() {
  scanf("%d%d", &n, &m);

  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;

  printf("%d\n", dp[n][m]);
}

// int배열로 했더니 오버플로가 생긴다.
// 그 외에 다른 문제는 그냥 공식대로 구하면 된다.
// F(N) = F(N - 1) + F(N - 2) 피보나치 공식을 이해한다면
// 차곡차곡 쌓아나가는건 쉬운 문제라 생각한다.