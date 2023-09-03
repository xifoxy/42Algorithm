#include <stdio.h>

int stair[11111], memo[11111];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) scanf("%d", j + stair);
    for (int j = 1; j <= i; j++)
      stair[j] += memo[j] > memo[j - 1] ? memo[j] : memo[j - 1];
    for (int j = 1; j <= i; j++) memo[j] = stair[j];
  }
  int max = 0;
  for (int i = 1; i <= n; i++) max = max > memo[i] ? max : memo[i];
  printf("%d\n", max);
}
