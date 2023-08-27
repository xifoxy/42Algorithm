#include <cstdio>

int n;
bool col[16];
bool in[32];
bool de[32];

int sol(int x) {
  if (x == n)
    return 1;

  int ret = 0;
  for (int i = 0; i < n; ++i) {
    if (col[i] || in[x + i] || de[n - 1 + x - i])
      continue;

    col[i] = in[x + i] = de[n - 1 + x - i] = true;
    ret += sol(x + 1);
    col[i] = in[x + i] = de[n - 1 + x - i] = false;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  printf("%d\n", sol(0));
}

// 퀸은 8방향으로 움직일 수 있다.
// 그러니 고려해야 할 부분은 3가지다
// 가로, 세로, 대각선 셋중 하나라도 겹치면 돌아가서 재탐색을 한다.