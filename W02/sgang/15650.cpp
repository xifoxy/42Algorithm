#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tmp;

int n, m;
string answer;
void solution(int curIndex, int depth) {
  if (depth == m) {
    for (const auto &p : tmp)
      answer += to_string(p) + ' ';
    answer.back() = '\n';
    return;
  }

  for (int i = curIndex; i <= n; ++i) {
    tmp.push_back(i);
    solution(i + 1, depth + 1);
    tmp.pop_back();
  }
}

int main() {
  cin >> n >> m;
  solution(1, 0);
  cout << answer;
}

// 4번 문제에서 조건을 하나 더 추가하면 된다.
// 코드로 표현해보자면...
/*
  for (d1 = 1)
    for (d2 = d1 + 1)
      for (d3 = d3 + 1)
*/