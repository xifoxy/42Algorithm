#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int n, arr[111], arr2[4];
int minn = 1e9, maxn = -1e9;
int (*op[4])(const int& a, const int& b) = {
    [](const int& a, const int& b) { return a + b; },
    [](const int& a, const int& b) { return a - b; },
    [](const int& a, const int& b) { return a * b; },
    [](const int& a, const int& b) { return a / b; }};

void rec(int index, int value) {
  if (index == n) {
    if (value > maxn) maxn = value;
    if (value < minn) minn = value;
  }
  for (int i = 0; i < 4; i++) {
    if (arr2[i]) {
      arr2[i]--;
      rec(index + 1, op[i](value, arr[index]));
      arr2[i]++;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < 4; i++) cin >> arr2[i];
  rec(1, arr[0]);
  cout << maxn << "\n" << minn << endl;
}

// 2주차에 재귀 푼 거랑 똑같이 모든 순서를 구하고
// 그것들로 계산해서 최소를 구함