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
    solution(i, depth + 1);
    tmp.pop_back();
  }
}

int main() {
  cin >> n >> m;
  solution(1, 0);
  cout << answer;
}

// 3번 문제에서 조건이 하나 걸린 문제이다.
// 코드로 표현해보자면...
/*
  for (d1 = 1)
    for (d2 = d1)
      for (d3 = d2)
*/
// 이러한 구조가 되기에, 재귀를 태울때 인덱스를 넘겨주면된다.
