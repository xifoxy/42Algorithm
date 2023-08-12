#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> tmp, num;
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
    if (num[i] == before_number)
      continue;
    before_number = num[i];
    tmp[depth] = num[i];
    solution(depth + 1);
  }
}

int main() {
  cin >> n >> m;
  num.resize(n);
  tmp.resize(m);
  for (int i = 0; i < n; ++i)
    cin >> num[i];
  sort(num.begin(), num.end());
  solution(0);
  cout << answer;
}

// 9번문제에 해설이 있기에 생략