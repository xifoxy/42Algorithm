#include <stdio.h>

int memo[33][33];

int combinations(int n, int r) {
  if (n == r || r == 0) return 1;
  if (memo[n][r] != 0) return memo[n][r];
  return memo[n][r] = combinations(n - 1, r - 1) + combinations(n - 1, r);
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < m)
      printf("%d\n", combinations(m, n));
    else
      printf("%d\n", combinations(n, m));
  }
}

// 간단한 조합 문제^^