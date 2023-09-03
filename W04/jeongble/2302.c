#include <stdio.h>

int memo[40][3];

int main(void) {
  memo[1][1] = memo[1][2] = 1;
  for (int i = 2; i <= 41; i++) {
    memo[i][0] = memo[i - 1][2];
    memo[i][1] = memo[i][2] = memo[i - 1][0] + memo[i - 1][1];
  }
  int n, m, res = 1;
  scanf("%d %d", &n, &m);
  int t = 1;
  while (m--) {
    int a;
    scanf("%d", &a);
    res *= memo[a - t + 1][1];
    t = a + 1;
  }
  printf("%d\n", res * memo[n - t + 2][1]);
}
