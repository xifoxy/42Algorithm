#include <deque>
#include <iostream>
#include <string>

using namespace std;

struct info {
  int num, idx;
};

string answer;
int n, a;
int cur, jump, sz;

int main() {
  cin >> n;
  deque<info> deq;

  for (int i = 0; i < n; ++i) {
    cin >> a;
    deq.push_back({a, i + 1});
  }

  for (int i = 0; i < n; ++i) {
    jump = deq[cur].num;
    answer += to_string(deq[cur].idx) + ' ';
    deq.erase(deq.begin() + cur);

    if (jump > 0)
      jump--;
    cur += jump;
    sz = deq.size();
    if (sz) {
      cur = cur >= 0 ? cur : sz + cur % sz;
      cur %= sz;
    }
  }

  answer.pop_back();
  cout << answer << '\n';
}

// 문제의 요구사항대로 구현하면 된다.
// 세그폴트가 안나게 인덱싱에 주의하자.