#include <cstdio>
#include <vector>

using namespace std;

const int M = 0x7fffffff;
int n, d[11], ans_min = M, ans_max = -M;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

void sol(vector<int> &oper, vector<int> &seq) {
  if (seq.size() == n - 1) {
    int s = d[0];
    for (int i = 1; i < n; ++i) {
      if (seq[i - 1] == 0)
        s += d[i];
      else if (seq[i - 1] == 1)
        s -= d[i];
      else if (seq[i - 1] == 2)
        s *= d[i];
      else
        s /= d[i];
    }
    ans_min = min(s, ans_min);
    ans_max = max(s, ans_max);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    if (!oper[i])
      continue;
    oper[i]--;
    seq.push_back(i);
    sol(oper, seq);
    oper[i]++;
    seq.pop_back();
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &d[i]);
  vector<int> oper(4), seq;
  for (int i = 0; i < 4; ++i)
    scanf("%d", &oper[i]);

  sol(oper, seq);
  printf("%d\n%d\n", ans_max, ans_min);
}

// N과 M을 제대로 공부했다면 쉽게 구할 수 있다.
// 연산자를 어디에 집어넣을껀지 조합을 구하면 된다.