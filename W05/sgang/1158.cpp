#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> que;
int n, k;
string answer;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    que.push(i);

  answer += '<';
  while (que.size()) {

    for (int i = 0; i < k - 1; ++i) {
      que.push(que.front());
      que.pop();
    }

    answer += to_string(que.front());
    que.pop();
    answer += (que.size() ? ", " : ">");
  }
  cout << answer << '\n';
}

// 요구사항대로 구현하면 된다.
// 주어진 K만큼 이동하고 제거하면 착오가 생길 수 있다.