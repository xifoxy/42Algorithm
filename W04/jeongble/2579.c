#include <stdio.h>

int stair[333], memo[333];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", i + stair);
  memo[0] = stair[0];
  memo[1] = stair[1];
  for (int i = 0; i < n; i++) {
    if (memo[i + 3] < memo[i] + stair[i + 1] + stair[i + 3])
      memo[i + 3] = memo[i] + stair[i + 1] + stair[i + 3];
    if (memo[i + 2] < memo[i] + stair[i + 2])
      memo[i + 2] = memo[i] + stair[i + 2];
  }
  if (memo[n - 1] < memo[n - 2] + stair[n - 1])
    memo[n - 1] = memo[n - 2] + stair[n - 1];
  printf("%d\n", memo[n - 1]);
}