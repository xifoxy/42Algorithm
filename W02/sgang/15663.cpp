#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tmp, num;
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

  int before_number = 0;
  for (int i = 0; i < n; ++i) {
    if (vst[i] || num[i] == before_number)
      continue;
    before_number = num[i];
    vst[i] = true;
    tmp[depth] = num[i];
    solution(depth + 1);
    vst[i] = false;
  }
}

int main() {
  cin >> n >> m;
  vst.resize(n);
  num.resize(n);
  tmp.resize(m);
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num.begin(), num.end());
  solution(0);
  cout << answer;
}

// 9~12번 문제도 생각보다 단순하다.
// 구조는 1~8과 같으나, 중복된 수열을 출력하지 않는 조건이 추가된다.
// 중복을 제거하는 가장 간단한 방법은 바로 직전에 썼던 숫자를
// 기록 해뒀다가 또 나타났을시 스킵하면 된다.