#include <stdio.h>

int memo[333333];
int bomb[33333];

int main(void) {
  int n, m;
  scanf("%d", &n);
  for (m = 1; (bomb[m - 1] = m * (m + 1) * (m + 2) / 6) <= n; m++) {
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; i + bomb[j] <= n; j++)
      if (!memo[i + bomb[j]] || memo[i] + 1 < memo[i + bomb[j]])
        memo[i + bomb[j]] = memo[i] + 1;
  printf("%d\n", memo[n]);
}