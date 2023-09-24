#include <cstdio>
#include <queue>
using namespace std;

int n, m, num, ans, mov;
queue<int> que;

int min(int a, int b) { return a > b ? b : a; }

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i)
    que.push(i);

  for (int i = 0; i < m; ++i) {
    scanf("%d", &num);

    mov = 0;

    while (que.front() != num) {
      que.push(que.front());
      que.pop();
      mov++;
    }

    ans += min(que.size() - mov, mov);
    que.pop();
  }

  printf("%d\n", ans);
}

// 설명대로 구현하면 된다.
// 뽑았을때 원하는 숫자가 나온다면,
// 큐 사이즈를 통해서 최솟값을 쉽게 구할 수 있다.