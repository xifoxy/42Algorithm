#include <iostream>
#include <string>

using namespace std;

int n;
bool vst[10];
string sign, vec;
string ans_max, ans_min;

bool check(char ch, int a, int b) {
  return (ch == '<' && a > b || ch == '>' && a < b) ? false : true;
}

void sol(string &num) {
  int sz = num.size();

  if (sz == sign.size() + 1) {
    if (!ans_min.size())
      ans_min = num;
    ans_max = num;
    return;
  }

  for (int i = 0; i <= 9; ++i) {
    if (vst[i] || !(check(sign[sz - 1], num.back() - '0', i)))
      continue;
    vst[i] = true;
    num.push_back(i + '0');
    sol(num);
    num.pop_back();
    vst[i] = false;
  }
}

int main() {
  cin >> n;
  sign.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> sign[i];
  sol(vec);
  cout << ans_max << '\n' << ans_min << '\n';
}

// N과 M을 공부했다면 쉽게 구현할 수 있다.
// 숫자의 조합과 부등호의 조합을 구하면 된다.