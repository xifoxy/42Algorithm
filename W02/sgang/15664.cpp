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

  int before_number = 0;
  for (int i = curIndex; i < n; ++i) {
    if (num[i] == before_number)
      continue;
    before_number = num[i];
    tmp[depth] = num[i];
    solution(i + 1, depth + 1);
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