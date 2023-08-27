#include <cstdio>

int d[222];
int s, n, ans;

int sol(int depth, int sum) {
  int ret = 0;
  if (depth == n)
    return 0;

  if (sum + d[depth] == s)
    ret++;

  ret += sol(depth + 1, sum);
  ret += sol(depth + 1, sum + d[depth]);
  return ret;
}

int main() {
  scanf("%d%d", &n, &s);
  for (int i = 0; i < n; ++i)
    scanf("%d", d + i);
  printf("%d\n", sol(0, 0));
}

// 재귀로 구현하면 쉽다.
// N의 크기가 20바밖에 안되기 때문에,
// 더하는 경우와 더하지 않는 재귀로 구현하면 된다.