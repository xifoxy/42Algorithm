#include <stdio.h>

int memo[1111] = {0, 1, 3};

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 3; i <= n; i++)
    memo[i] = (memo[i - 1] + memo[i - 2] * 2) % 10007;
  printf("%d\n", memo[n]);
  return (0);
}
