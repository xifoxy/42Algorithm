#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tmp;
vector<bool> vst;

int n, m;
string answer;
void solution(int depth) {
  if (depth == m) {
    for (const auto &p : tmp)
      answer += to_string(p) + ' ';
    answer.back() = '\n';
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (vst[i])
      continue;
    vst[i] = true;
    tmp.push_back(i);
    solution(depth + 1);
    tmp.pop_back();
    vst[i] = false;
  }
}

int main() {
  cin >> n >> m;
  vst.resize(n + 1);
  solution(0);
  cout << answer;
}

// 이 문제는 인덱스의 중복이 생기면 안된다.
// 그러니 중복을 피할 수 있는 visit배열을 만들어 중복 체크를 해준다.