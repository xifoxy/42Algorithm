#include <iostream>
#include <vector>

using namespace std;

struct info {
  int n, s, b;
};

int n, cnt, strike, ball, ans;
vector<info> information;
vector<int> num1, num2;

void fn(vector<int> &ret, int num) {
  if (!num)
    return;
  fn(ret, num / 10);
  ret.push_back(num % 10);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int aa, bb, cc;
    cin >> aa >> bb >> cc;
    information.push_back({aa, bb, cc});
  }

  for (int i = 123; i <= 987; ++i) {
    cnt = 0;
    num1.clear();
    fn(num1, i);
    // 0을 걸러내자
    if (!num1[0] || !num1[1] || !num1[2])
      continue;
    // 중복을 걸러내자
    if (num1[0] == num1[1] || num1[1] == num1[2] || num1[2] == num1[0])
      continue;

    for (int j = 0; j < n; ++j) {
      strike = ball = 0;
      num2.clear();
      fn(num2, information[j].n);

      for (int k = 0; k < 3; ++k) {
        // 스트라이크
        if (num1[k] == num2[k])
          strike++;
        // 다른곳에 숫자가 등장한다면 볼이다.
        if (num1[k] == num2[(k + 1) % 3] || num1[k] == num2[(k + 2) % 3])
          ball++;
      }

      // 볼카운트와 스트라이크 카운트가 동일한걸 체크해서
      if (strike == information[j].s && ball == information[j].b)
        cnt++;
    }
    // 주어진 케이스를 비교해서 답으로 유추되는 조건을 찾았다면 답 증가
    if (cnt == n)
      ans++;
  }
  cout << ans << '\n';
}

// 문제의 조건에선 케이스 하나당 중복되지 않는 숫자로 주어진다고 한다.
// 이것은 신경안써도 되지만 문제를 풀기위해 조건을 검사하는 과정에서 예외 처리를
// 좀 할 필요가 있다.