#include <stdio.h>

int memo[1111][1111];

int rec(int n, int m) {
  if (n == 0 || m == 0) return 1;
  if (memo[n][m] != 0) return memo[n][m];
  return memo[n][m] = ((rec(n - 1, m - 1) + rec(n - 1, m)) % 1000000007 +
                       rec(n, m - 1)) %
                      1000000007;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", rec(n - 1, m - 1));
}