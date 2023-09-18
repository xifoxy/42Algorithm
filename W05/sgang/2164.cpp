#include <cstdio>
#include <queue>

using namespace std;

queue<int> que;
int n;

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i)
    que.push(i);

  while (que.size() != 1) {
    que.pop();
    que.push(que.front());
    que.pop();
  }

  printf("%d\n", que.front());
}

// 문제의 요구사항대로 큐에 남은 숫자가 하나일때까지 돌리자