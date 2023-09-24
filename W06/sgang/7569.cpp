#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

const int S = 1e2 + 1;

struct info {
  int z, x, y;
};
int dx[]{1, -1, 0, 0, 0, 0};
int dy[]{0, 0, 1, -1, 0, 0};
int dz[]{0, 0, 0, 0, 1, -1};

int n, m, h, zero, over;
int d[S][S][S];

queue<info> Q;

bool safe(int x, int y, int z) {
  return min(x, min(y, z)) >= 0 && x < n && y < m && z < h;
}

int bfs() {
  int ret = 0;
  while (!Q.empty()) {
    auto p = Q.front();
    Q.pop();
    for (int Direction = 0; Direction < 6; ++Direction) {
      int nx = p.x + dx[Direction];
      int ny = p.y + dy[Direction];
      int nz = p.z + dz[Direction];

      if (!safe(nx, ny, nz) || d[nz][nx][ny])
        continue;

      d[nz][nx][ny] = d[p.z][p.x][p.y] + 1;
      Q.push({nz, nx, ny});
      ret = max(ret, d[nz][nx][ny]);
      --zero;
    }
  }
  return ret;
}

int main() {
  scanf("%d%d%d", &m, &n, &h);

  for (int z = 0; z < h; ++z) {
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < m; ++y) {
        scanf("%d", &d[z][x][y]);

        if (!d[z][x][y])
          zero++;
        if (d[z][x][y] == 1) {
          Q.push({z, x, y});
          over++;
        }
      }
    }
  }
  int ans = bfs();
  if (!zero && over)
    printf("%d\n", ans ? ans - 1 : 0);
  else
    puts("-1");
}

// 이 문제에서 주의해야할 점은 입력받은 n, m, h의 위치만 잘 구별해주면
// 크게 문제가 안생길것 같다.
// 답에 대한 zero와 over는 익지 않은 토마토와 익은 토마토를 가르킨다.