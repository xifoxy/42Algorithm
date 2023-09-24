#include <cstdio>

const int SZ = 55;

int bd[SZ][SZ];
int w, h;
int dx[]{1, -1, 0, 0, -1, -1, 1, 1};
int dy[]{0, 0, 1, -1, -1, 1, -1, 1};
int component;

int min(int x, int y) { return x > y ? y : x; }
int safe(int x, int y) { return min(x, y) >= 0 && x < h && y < w && bd[x][y]; }

void dfs(int x, int y) {
  bd[x][y] = 0;

  for (int Direction = 0; Direction < 8; ++Direction) {
    int nx = x + dx[Direction];
    int ny = y + dy[Direction];
    if (!safe(nx, ny))
      continue;
    dfs(nx, ny);
  }
}

int main() {
  while (scanf("%d%d", &w, &h), w) {
    component = 0;
    for (int x = 0; x < h; ++x)
      for (int y = 0; y < w; ++y)
        scanf("%d", &bd[x][y]);

    for (int x = 0; x < h; ++x) {
      for (int y = 0; y < w; ++y) {
        if (!bd[x][y])
          continue;
        component++;
        dfs(x, y);
      }
    }
    printf("%d\n", component);
  }
}

// 섬의 갯수를 구하는 문제, 뒤집어 이야기하면 컴포넌트가 몇개인지 묻는 문제다.
// 조건에 맞게 탐색만 잘해주면 된다.