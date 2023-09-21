#include <cstdio>

const int SZ = 1e3 + 1;
int n;
int d[3][SZ];

int min(int a, int b) { return a > b ? b : a; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d", d[0] + i, d[1] + i, d[2] + i);

  for (int i = 1; i <= n; ++i) {
    d[0][i] += min(d[1][i - 1], d[2][i - 1]);
    d[1][i] += min(d[0][i - 1], d[2][i - 1]);
    d[2][i] += min(d[0][i - 1], d[1][i - 1]);
  }

  printf("%d\n", min(d[0][n], min(d[1][n], d[2][n])));
}

// 뭔가 되게 복잡해 보이지만
// 조건 그대로 구현하면된다. 서로 피해주지말자