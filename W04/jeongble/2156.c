#include <stdio.h>

int stair[11111], memo[11111];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", i + stair);
  if (n == 1) {
    printf("%d\n", stair[0]);
    return 0;
  }
  memo[0] = stair[0];
  memo[1] = stair[1];
  for (int i = 0; i < n; i++) {
    if (memo[i + 4] < memo[i] + stair[i + 1] + stair[i + 4])
      memo[i + 4] = memo[i] + stair[i + 1] + stair[i + 4];
    if (memo[i + 3] < memo[i] + stair[i + 1] + stair[i + 3])
      memo[i + 3] = memo[i] + stair[i + 1] + stair[i + 3];
    if (memo[i + 2] < memo[i] + stair[i + 2])
      memo[i + 2] = memo[i] + stair[i + 2];
  }
  if (n >= 2 && memo[n - 1] < memo[n - 2] + stair[n - 1])
    memo[n - 1] = memo[n - 2] + stair[n - 1];
  if (n >= 3 && memo[n - 2] < memo[n - 3] + stair[n - 2])
    memo[n - 2] = memo[n - 3] + stair[n - 2];
  printf("%d\n", memo[n - 1] > memo[n - 2] ? memo[n - 1] : memo[n - 2]);
}

// 2579의 계단 문제랑 똑같은 문제인가 했는데
// 99 0 0 99 처럼 3칸 움직여야 할 때도 있음