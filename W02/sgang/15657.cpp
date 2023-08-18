#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tmp, num;

int n, m;
string answer;
void solution(int curIndex, int depth) {
  if (depth == m) {
    for (const auto &p : tmp)
      answer += to_string(p) + ' ';
    answer.back() = '\n';
    return;
  }

  for (int i = curIndex; i < n; ++i) {
    tmp[depth] = num[i];
    solution(i, depth + 1);
  }
}

int main() {
  cin >> n >> m;
  num.resize(n);
  tmp.resize(m);
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num.begin(), num.end());
  solution(0, 0);
  cout << answer;
}

// 5~8은 1~4문제에서 입력만 추가되었기에 생략