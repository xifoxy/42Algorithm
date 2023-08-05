#include <algorithm>
#include <cstdio>

using namespace std;

const int MX = 99;
char b[MX][MX];
int n, m;
int ans = MX * MX;

int sol(int x, int y) {
  int ret = 0;
  for (int i = x; i < x + 8; ++i) {
    for (int j = y; j < y + 8; ++j) {
      if ((i + j) % 2 && b[i][j] != 'B')
        ret++;
      if ((i + j) % 2 == 0 && b[i][j] != 'W')
        ret++;
    }
  }
  return min(ret, 64 - ret);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%s", *(b + i));

  for (int i = 0; i < n - 7; ++i)
    for (int j = 0; j < m - 7; ++j)
      ans = min(ans, sol(i, j));
  printf("%d\n", ans);
}

// 완전 탐색이다.
// BW, WB 두개 중 어느 것으로 시작해도 상관없으니,
// 바꿔야 하는 갯수가 작은걸 택하면 된다.