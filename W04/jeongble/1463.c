#include <stdio.h>
int memo[1111111];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (i + 1 <= n && (!memo[i + 1] || memo[i] + 1 < memo[i + 1]))
      memo[i + 1] = memo[i] + 1;
    if (i * 2 <= n && (!memo[i * 2] || memo[i] + 1 < memo[i * 2]))
      memo[i * 2] = memo[i] + 1;
    if (i * 3 <= n && (!memo[i * 3] || memo[i] + 1 < memo[i * 3]))
      memo[i * 3] = memo[i] + 1;
  }
  printf("%d\n", memo[n]);
}