#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tmp;

int n, m;
string answer;
void solution(int depth) {
  // 탈출조건(깊이가 M이라는 말은 0~M-1의 깊이를 넘어섰기에)
  if (depth == m) {
    for (const auto &p : tmp)
      answer += to_string(p) + ' ';
    answer.back() = '\n';
    // 오버헤드를 줄이기위해 스트링에 담아둔다.
    return;
  }
  for (int i = 1; i <= n; ++i) {
    // 현재 depth에서 출력할 숫자를 저장하고
    tmp.push_back(i);
    solution(depth + 1);
    // 출력이 끝났기에 숫자를 빼준다.
    tmp.pop_back();
  }
}

int main() {
  cin >> n >> m;
  solution(0); // solution함수 자체가 다중 반복문이다.
  cout << answer;
}

// NM시리즈는 수열과 조합을 구하는 문제이다.
// 3번 문제는 가장 기초적인 M중 반복문을 재귀로 구현하면 된다.
// 모든 반복문의 인덱스가 1~N까지 반복되며, 깊이가 M인 반복문을 구현하면된다.
// 코드로 표현해보자면...
/*
  for (d1 = 1; d1 <= n; ++d1)
    for (d2 = 1; d2 <= n; ++d2)
      for (d3 = 1; d3 <= n; ++d3)
*/