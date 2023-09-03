#include <cstdio>
#include <vector>

using namespace std;

int a[8], n, ans;
bool vst[8];
vector<int> vec;

int mmax(int a, int b) { return a > b ? a : b; }
int aabs(int a) { return a < 0 ? -a : a; }

void sol() {
  if (vec.size() == n) {
    int temp = 0;
    for (int i = 1; i < n; ++i) {
      temp += aabs(vec[i - 1] - vec[i]);
    }
    ans = mmax(ans, temp);
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (vst[i])
      continue;
    vec.push_back(a[i]);
    vst[i] = true;
    sol();
    vst[i] = false;
    vec.pop_back();
  }
}
int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  sol();
  printf("%d\n", ans);
}

// 문제에 백트레킹 요소가 있다.
// N과 M에서 공부를 잘 했다면, 쉽게 구현할 수 있다.